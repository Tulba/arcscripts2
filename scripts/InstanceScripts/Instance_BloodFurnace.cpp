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

// Keli'dan the BreakerAI

#define CN_KELIDAN_THE_BREAKER			17377

#define KELIDAN_BURNING_NOVA			30940
#define KELIDAN_SHADOW_BOLT_VOLLEY		28599
#define KELIDAN_SHADOW_BOLT_VOLLEY_H	40070
#define KELIDAN_FIRE_NOVA				33132
#define KELIDAN_FIRE_NOVA_H				37371
#define KELIDAN_CORRUPTION				30938
#define KELIDAN_EVOCATION				30935
#define KELIDAN_VORTEX					37370

class KelidanTheBreakerAI : public CreatureAI
{
	public:
		ADD_CREATURE_FACTORY_FUNCTION(KelidanTheBreakerAI)
		KelidanTheBreakerAI(Creature* pCreature) : CreatureAI(pCreature)
		{
			//spells
			mShadowBoltVolley = AddSpell(KELIDAN_SHADOW_BOLT_VOLLEY, Target_Self, 25, 0, 6);
			mFireNova = AddSpell(KELIDAN_FIRE_NOVA, Target_Self, 15, 0, 12);

			mBurningNova = AddSpell(KELIDAN_BURNING_NOVA, Target_Self, 0, 0, 0);
			mBurningNova->AddEmote("Closer! Come closer... and burn!", Text_Yell);
			mVortex = AddSpell(KELIDAN_FIRE_NOVA, Target_Self, 0, 0, 0);
			AddSpell(KELIDAN_CORRUPTION, Target_Current, 15, 0, 10);

			AddEmote(Event_OnCombatStart, "Who dares interrupt--What is this, what have you done? You'll ruin everything!", Text_Yell);
			AddEmote(Event_OnTargetDied, "Just as you deserve.", Text_Yell);
			AddEmote(Event_OnTargetDied, "Your friends will soon be joining you.", Text_Yell);
			AddEmote(Event_OnDied, "Good... luck. You'll need it.", Text_Yell);

			mBurningNovaTimer = INVALIDATE_TIMER;
			SetAIUpdateFreq(800);
		}

		void OnCombatStart(Unit* pTarget)
		{
			mBurningNovaTimer = AddTimer(15000);
		}

		void AIUpdate()
		{
			if(IsTimerFinished(mBurningNovaTimer))
			{
				if(IsHeroic())
					CastSpell(mVortex);

				CastSpell(mBurningNova);

				ResetTimer(mBurningNovaTimer, 30000);
			}
		}

		SpellDesc*      mShadowBoltVolley;
		SpellDesc*      mFireNova;
		SpellDesc*      mBurningNova;
		SpellDesc*      mVortex;
		int32           mBurningNovaTimer;
};

//------------------------------------
//	-= Broggok =-
//------------------------------------
#define CN_BROGGOK 17380

#define POISON_BOLT 30917
#define POISON_CLOUD 31259 // DBC: 30916; no idea if correct
#define SLIME_SPRAY 30913

class BroggokAI : public CreatureAI
{
	public:
		ADD_CREATURE_FACTORY_FUNCTION(BroggokAI);
		BroggokAI(Creature* pCreature) : CreatureAI(pCreature)
		{
			AddSpell(POISON_BOLT, Target_Self, 12.0f, 0, 15);
			AddSpell(POISON_CLOUD, Target_RandomPlayerDestination, 8.0f, 0, 40, 0, 40);
			AddSpell(SLIME_SPRAY, Target_Self, 10.0f, 0, 25);
		}

		void OnDied(Unit* pKiller)
		{
			if(GameObject* pDoor = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(456.157349f, 34.248005f, 9.559463f, 181819))
				pDoor->SetState(GAMEOBJECT_STATE_OPEN);
		}
};

//------------------------------------
//	-= The Maker =-
//------------------------------------
#define CN_THE_MAKER 17381

#define DOMINATION 30923 // 36866
#define ACID_SPRAY 38973 // 38973 or 38153	// not sure about casting of this
#define THROW_BEAKER 30925 // Throw beaker <--- maybe this is it?

class TheMakerAI : public CreatureAI
{
	public:
		ADD_CREATURE_FACTORY_FUNCTION(TheMakerAI);
		TheMakerAI(Creature* pCreature) : CreatureAI(pCreature)
		{
			AddEmote(Event_OnCombatStart, "My work must not be interrupted.", Text_Yell, 10286);
			AddEmote(Event_OnCombatStart, "Perhaps I can find a use for you.", Text_Yell, 10287);
			AddEmote(Event_OnCombatStart, "Anger... Hate... These are tools I can use.", Text_Yell, 10288);
			AddEmote(Event_OnTargetDied, "Let's see what I can make of you.", Text_Yell, 10289);
			AddEmote(Event_OnTargetDied, "It is pointless to resist.", Text_Yell, 10290);
			AddEmote(Event_OnDied, "Stay away from... me.", Text_Yell, 10291);

			AddSpell(DOMINATION, Target_RandomPlayer, 8.0f, 0, 30);
			AddSpell(ACID_SPRAY, Target_Self, 10.0f, 0, 20);
			AddSpell(THROW_BEAKER, Target_RandomPlayerDestination, 20.0f, 0, 0, 0, 40);
		}

		void OnDied(Unit* pKiller)
		{
			if(GameObject* pDoor = _unit->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords(327.155487f, 149.753418f, 9.559869f, 181812))
				pDoor->SetState(GAMEOBJECT_STATE_OPEN);
		}
};

void SetupBloodFurnace(ScriptMgr* mgr)
{
	mgr->register_creature_script(CN_KELIDAN_THE_BREAKER, &KelidanTheBreakerAI::Create);
	mgr->register_creature_script(CN_BROGGOK, &BroggokAI::Create);
	mgr->register_creature_script(CN_THE_MAKER, &TheMakerAI::Create);
}
