/*
 * WhyScript Scripts for Arcemu MMORPG Server
 * Copyright (C) 2010 WhyDB Team <http://www.whydb.org/>
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

class Obsidias_Egg : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(Obsidias_Egg)
	Obsidias_Egg(GameObject *goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player *pPlayer)
	{
		LocationVector vect( pPlayer->GetPositionX()+RandomFloat(2.0f), pPlayer->GetPositionY()+RandomFloat(2.0f), pPlayer->GetPositionZ(), pPlayer->GetOrientation() );
		if( pPlayer->HasQuest(11078) )
			sEAS.SpawnCreature( pPlayer, 23282, vect, DESPAWN_TIME );
	}
};

class Rivendarks_Egg : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(Rivendarks_Egg)
	Rivendarks_Egg(GameObject *goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player *pPlayer)
	{
		LocationVector vect( pPlayer->GetPositionX()+RandomFloat(2.0f), pPlayer->GetPositionY()+RandomFloat(2.0f), pPlayer->GetPositionZ(), pPlayer->GetOrientation() );
		if( pPlayer->HasQuest(11078) )
			sEAS.SpawnCreature( pPlayer, 23061, vect, DESPAWN_TIME );
	}
};

class Furywings_Egg : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(Furywings_Egg)
	Furywings_Egg(GameObject *goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player *pPlayer)
	{
		LocationVector vect( pPlayer->GetPositionX()+RandomFloat(2.0f), pPlayer->GetPositionY()+RandomFloat(2.0f), pPlayer->GetPositionZ(), pPlayer->GetOrientation() );
		if( pPlayer->HasQuest(11078) )
			sEAS.SpawnCreature( pPlayer, 23261, vect, DESPAWN_TIME );
	}
};

class Insidions_Egg : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(Insidions_Egg)
	Insidions_Egg(GameObject *goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player *pPlayer)
	{
		LocationVector vect( pPlayer->GetPositionX()+RandomFloat(2.0f), pPlayer->GetPositionY()+RandomFloat(2.0f), pPlayer->GetPositionZ(), pPlayer->GetOrientation() );
		if( pPlayer->HasQuest(11078) )
			sEAS.SpawnCreature( pPlayer, 23281, vect, DESPAWN_TIME );
	}
};

class TheThunderspike : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(TheThunderspike)
	TheThunderspike(GameObject *goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player *pPlayer)
	{
		GameObject *gobj = sEAS.GetNearestGameObject(pPlayer, 184729);
		if( pPlayer->HasQuest(10526) )
		{
			_gameobject->Despawn( 0, DESPAWN_TIME );
			sEAS.SpawnCreature( pPlayer, 21319, 1315.54f, 6688.33f, -18, 0.001f, DESPAWN_TIME );
		}
	}
};

class PowerConverter : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(PowerConverter)
	PowerConverter(GameObject * goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player * pPlayer)
	{
		if( pPlayer->HasQuest( 10584 ) )
		{
			Creature *Elec = sEAS.SpawnCreature( pPlayer, 21729, _gameobject->GetPositionNC(), DESPAWN_TIME );
			Elec->GetAIInterface()->AttackReaction( pPlayer, 1 );
		}
		_gameobject->Despawn( 0, DESPAWN_TIME );
	}
};

class NetherEgg : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(NetherEgg)
	NetherEgg(GameObject * goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player * pPlayer)
	{
		if( pPlayer->HasQuest( 10609 ) )
		{
			uint32 itemcount = pPlayer->GetItemInterface()->GetItemCount( 30743, true );
			itemcount += pPlayer->GetItemInterface()->GetItemCount( 30782, true );
			itemcount += pPlayer->GetItemInterface()->GetItemCount( 30783, true );
			if( itemcount <= 9 && itemcount == (rand()%itemcount + 9) )
				sEAS.SpawnCreature( _gameobject, 21823, _gameobject->GetPositionNC(), DESPAWN_TIME );
			else
				_gameobject->CastSpell( _gameobject, 36326, true );
		}
		_gameobject->Despawn( 0, DESPAWN_TIME );
	}
};

class LegionObelisk : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(LegionObelisk)
	LegionObelisk(GameObject * goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player * pPlayer)
	{
		if( !pPlayer->HasQuest( 10821 ) )
			return;

		GameObject *obelisk1 = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords( 2898.92f, 4759.29f, 277.408f, 185198 );
		GameObject *obelisk2 = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords( 2942.30f, 4752.28f, 285.553f, 185197 );
		GameObject *obelisk3 = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords( 2834.39f, 4856.67f, 277.632f, 185196 );
		GameObject *obelisk4 = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords( 2923.37f, 4840.36f, 278.450f, 185195 );
		GameObject *obelisk5 = pPlayer->GetMapMgr()->GetInterface()->GetGameObjectNearestCoords( 2965.75f, 4835.25f, 277.949f, 185193 );
		if( !obelisk1 || !obelisk2 || !obelisk3 || !obelisk4 || !obelisk5 )
			return;

		_gameobject->SetState( 0 );
		if( obelisk1->GetState() == 0 && obelisk2->GetState() == 0 && obelisk3->GetState() == 0 && obelisk4->GetState() == 0 && obelisk5->GetState() == 0 )
			sEAS.SpawnCreature( pPlayer, 19963, 2943.59f, 4779.05f, 284.49f, 1.89f, DESPAWN_TIME );

		sEventMgr.AddEvent( obelisk1, &GameObject::SetState, (uint8)1, EVENT_UNK, 600000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
		sEventMgr.AddEvent( obelisk2, &GameObject::SetState, (uint8)1, EVENT_UNK, 600000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
		sEventMgr.AddEvent( obelisk3, &GameObject::SetState, (uint8)1, EVENT_UNK, 600000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
		sEventMgr.AddEvent( obelisk4, &GameObject::SetState, (uint8)1, EVENT_UNK, 600000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
		sEventMgr.AddEvent( obelisk5, &GameObject::SetState, (uint8)1, EVENT_UNK, 600000, 1, EVENT_FLAG_DO_NOT_EXECUTE_IN_WORLD_CONTEXT );
	}
};

class StasisChamberAlpha : public GameObjectAIScript
{
public:
	ADD_GAMEOBJECT_FACTORY_FUNCTION(StasisChamberAlpha)
	StasisChamberAlpha(GameObject *goinstance) : GameObjectAIScript(goinstance) {}

	void OnActivate(Player *pPlayer)
	{
		if( !pPlayer->HasQuest(10974) )
			return;

		Creature *pCreature = pPlayer->GetMapMgr()->GetInterface()->GetCreatureNearestCoords( 3989.094482f, 6071.562500f, 266.416656f, 22920 );
		if( pCreature != NULL )
		{
			pCreature->SetFaction( 14 );
			pCreature->SetScale( 1.0f );
			pCreature->GetAIInterface()->setNextTarget( pPlayer );
			pCreature->GetAIInterface()->AttackReaction( pPlayer, 1 );
		}
	}
};

void SetupBladeEdgeMountainsGameobjects(ScriptMgr * mgr)
{
	mgr->register_gameobject_script( 185932, &Obsidias_Egg::Create );			// Obsidia's Egg
	mgr->register_gameobject_script( 185936, &Rivendarks_Egg::Create );			// Rivendark's Egg
	mgr->register_gameobject_script( 185937, &Furywings_Egg::Create );			// Furywing's Egg
	mgr->register_gameobject_script( 185938, &Insidions_Egg::Create );			// Insidion's Egg
	mgr->register_gameobject_script( 184729, &TheThunderspike::Create );		// The Thunderspike
	mgr->register_gameobject_script( 184906, &PowerConverter::Create );			// Power Converter
	mgr->register_gameobject_script( 184867, &NetherEgg::Create );				// Nether Drake Egg
	uint32 LegionObliskIds[] = { 185193, 185195, 185196, 185197, 185198, 0 };
	mgr->register_gameobject_script( LegionObliskIds, &LegionObelisk::Create );	// Legion Obelisk
	mgr->register_gameobject_script( 185512, &StasisChamberAlpha::Create );		// Stasis Chamber Alpha
}