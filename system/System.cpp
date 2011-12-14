
#include "Setup.h"
#include "System.h"

void ArcScripts2::LoadScriptTexts()
{
    QueryResult* pResult = WorldDatabase.Query("SELECT entry, text, type, sound, emote FROM script_texts WHERE entry BETWEEN %i AND %i", TEXT_SOURCE_TEXT_END, TEXT_SOURCE_TEXT_START);
	if(!pResult)
	{
		LOG_ERROR("ArcScripts2: Loaded 0 additional Script Texts data. DB table `script_texts` is empty");
		return;
	}

	uint32 count = 0;

    do
    {
		Field* pFields = pResult->Fetch();

		StringTextData pTemp;
		int32 iId           = pFields[0].GetInt32();
		pTemp.uiText        = pFields[1].GetString();
		pTemp.uiType        = pFields[2].GetUInt32();
		pTemp.uiSoundId     = pFields[3].GetUInt32();
		pTemp.uiEmote       = pFields[4].GetUInt32();

		if(pTemp.uiText == NULL)
		{
			LOG_ERROR("ArcScripts2: Entry %i in table `script_texts` has no text data", iId);
			continue;
		}

		if(iId >= 0)
		{
			LOG_ERROR("ArcScripts2: Entry %i in table `script_texts` is not a negative value.", iId);
			continue;
		}

        m_mTextDataMap[iId] = pTemp;
		count++;
    } while (pResult->NextRow());

    delete pResult;
    Log.Success("ArcScripts2:", "Loaded %u additional Script Texts data.", count);
}