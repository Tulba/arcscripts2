/*
 * ArcScripts2 Scripts for Arcemu MMORPG Server
 * Copyright (C) 2011-2012 ArcScripts2 team
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Setup.h"

class MobsGhoulFlayer : public MoonScriptCreatureAI
{
	public:
		MOONSCRIPT_FACTORY_FUNCTION(MobsGhoulFlayer, MoonScriptCreatureAI);
		MobsGhoulFlayer(Creature* pCreature) : MoonScriptCreatureAI(pCreature){}

		void OnDied(Unit *mKiller)
		{
			if(!mKiller->IsPlayer())
				return;

			MoonScriptCreatureAI * c = SpawnCreature(11064, _unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), _unit->GetOrientation());
			if(c)
				c->Despawn(60*SEC_IN_MS);
		}
};

class ArajTheSummoner : public MoonScriptCreatureAI
{
	public:
		MOONSCRIPT_FACTORY_FUNCTION(ArajTheSummoner, MoonScriptCreatureAI);
		ArajTheSummoner(Creature* pCreature) : MoonScriptCreatureAI(pCreature){}

		void OnDied(Unit* mKiller)
		{
			if(!mKiller->IsPlayer())
				return;

			GameObject* go = sEAS.SpawnGameobject(TO_PLAYER(mKiller), 177241, _unit->GetPositionX(), _unit->GetPositionY(), _unit->GetPositionZ(), _unit->GetOrientation(), 1, 0, 0, 0, 0);
			if(go)
				sEAS.GameobjectDelete(go, 60000);
		}
};

void SetupEasternPlaguelandsCreatures(ScriptMgr * mgr)
{
	mgr->register_creature_script(8530,  &MobsGhoulFlayer::Create);
	mgr->register_creature_script(8531,  &MobsGhoulFlayer::Create);
	mgr->register_creature_script(8532,  &MobsGhoulFlayer::Create);
	mgr->register_creature_script(1852, &ArajTheSummoner::Create);
}