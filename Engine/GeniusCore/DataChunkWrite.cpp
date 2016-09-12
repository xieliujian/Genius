

#include "DataChunkWrite.h"

NAMESPACEBEGIN(Genius)

DataChunkWrite::DataChunkWrite(uint32 dwBufferSize, bool bSkip0SizeChunk)
{
	m_dwBufferSize = dwBufferSize;
	m_pbyBuffer = new uint8[dwBufferSize];
	m_dwOffset = 0;
	m_bExternalMemory = false;
	m_bSkip0SizeChunk = bSkip0SizeChunk;
}

DataChunkWrite::~DataChunkWrite()
{

}

uint32 DataChunkWrite::Write(void* pBuffer, uint32 dwBlockSize, uint32 dwBlockCount)
{
	if (m_bExternalMemory)
	{
		if (m_dwOffset + dwBlockSize * dwBlockCount > m_dwBufferSize)
		{
			assert(false);
			return 0;
		}
	}
	else
	{
		while (m_dwOffset + dwBlockSize * dwBlockCount > m_dwBufferSize)
		{
			uint32 dwNewBufferSize = m_dwBufferSize * 2;
			uint8* pbyNewBuffer = new uint8[dwNewBufferSize];
			memcpy(pbyNewBuffer, m_pbyBuffer, min(m_dwBufferSize, dwNewBufferSize));
			SAFE_DELETE_ARRAY(m_pbyBuffer);
			m_pbyBuffer = pbyNewBuffer;
			m_dwBufferSize = dwNewBufferSize;
		}
	}

	uint8* pSrc = (uint8*)pBuffer;
	for (uint32 i = 0; i < dwBlockCount; i++)
	{
		memcpy(&m_pbyBuffer[m_dwOffset], pSrc, dwBlockSize);
		pSrc += dwBlockSize;
		m_dwOffset += dwBlockSize;
	}

	return m_dwOffset;
}

uint32 DataChunkWrite::StartChunk(uint32 dwName)
{
	ChunkDesc desc;
	desc.header.dwName = dwName;
	desc.header.dwSize = 0;
	desc.dwOffset = m_dwOffset;
	m_stackChunkDesc.push(desc);

	Write(&desc.header, sizeof(ChunkHdr), 1);
	return 0;
}

uint32 DataChunkWrite::EndChunk(uint32 dwName)
{
	assert(!m_stackChunkDesc.empty());
	ChunkDesc desc = m_stackChunkDesc.top();
	m_stackChunkDesc.pop();

	assert(desc.header.dwName == dwName);
	if (desc.dwOffset > m_dwBufferSize)
	{
		assert(false);
		return 0;
	}

	ChunkHdr* pHdr = (ChunkHdr*)&m_pbyBuffer[desc.dwOffset];
	pHdr->dwSize = m_dwOffset - (desc.dwOffset + sizeof(ChunkHdr));
	if (m_bSkip0SizeChunk && pHdr->dwSize == 0)
		m_dwOffset = desc.dwOffset;

	return 0;
}

uint32 DataChunkWrite::WriteInt(int i)
{
	return Write(&i, sizeof(int), 1);
}

uint32 DataChunkWrite::WriteString(char* str)
{
	uint32 dwOffset = WriteInt(strlen(str));
	if (strlen(str) > 0)
		return Write(str, strlen(str), 1);
	return dwOffset;
}

bool DataChunkWrite::SaveToFile(const char* pszFilename)
{
	assert(m_stackChunkDesc.empty());
	FILE* fp = NULL;
	fopen_s(&fp, pszFilename, "wb");
	if (!fp)
		return false;

	if (m_dwOffset == 0)
		return false;

	fwrite(m_pbyBuffer, m_dwOffset, 1, fp);
	fclose(fp);
	return true;
}

void DataChunkWrite::Destroy()
{
	if (m_bExternalMemory)
	{
		m_pbyBuffer = NULL;
	}
	else
	{
		SAFE_DELETE_ARRAY(m_pbyBuffer);
	}

	m_dwBufferSize = 0;
	m_dwOffset = 0;
}

NAMESPACEEND