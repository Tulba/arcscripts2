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
 *
 * Original script by Nexis.
 */

#include "Setup.h"

//#define SETUP // Uncomment if the carnis should bark their setup messages.

// Sayge
#define BARK_SAYGE_1	"Fear not! All fortunes can be discerned for those who know the way."
#define BARK_SAYGE_2	"The longer you wait, the less future you have for me to foretell."
#define BARK_SAYGE_3	"Come speak with me, and what once was cloudy shall become crystal clear."
#define BARK_SAYGE_4	"Come to me true believers, and see what the future holds for you!"

class Sayge : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Sayge)
	Sayge(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 135000 ); // Start initial update after: 2.25mins
	}

	void AIUpdate()
	{
		switch( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SAYGE_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SAYGE_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SAYGE_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SAYGE_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 180000 + 300000 ); // Modify timer to a random value between: 3-5mins
	}
};

// Silas Darkmoon
#define BARK_SILAS_DARKMOON_1	"Welcome one and all to the greatest show on all of Azeroth... the Darkmoon Faire! Adventure and excitement await, don't be shy! Mysteries and prizes for both the young and the old are here for the taking. And be sure to speak with the professor about any Darkmoon Cards that you have come across during your travels!"
#define BARK_SILAS_DARKMOON_2	"Come one, come all. Welcome to the Darkmoon Faire! Don't be shy. Step right up to Lhara and buy yourself an exotic artifact from far off lands. If you're one of the lucky few who have found Darkmoon Cards, have a word with Professor Paleo. Hungry? Thirsy? You're in luck! Refreshments are available right here from Sylannia and Stamp. I recommend the Darkmoon Special Reserve to wash down some Red Hot Wings. And if the future is what you seek, then run, don't walk, to speak with Sayge."
#define BARK_SILAS_DARKMOON_3	"We're back and better than ever! It's the Darkmoon Faire friend, and it's your lucky day! Sparing no expense, we've gathered wonders and treats from around the world for your delight. Wheather you're young or old, rich or poor, the Darkmoon Faire has it all! Be sure to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate, and choose from several exotic and wonderous prizes!"
#define BARK_SILAS_DARKMOON_4	"Welcome one and all to the Darkmoon Faire, the greatest event in the world! We have it all... delicious food, strong drink, exotic artifacts, fortunes read, amazing prizes and excitement without end! Don't forget to turn in your Darkmoon Faire Prize Tickets to Gelvas Grimegate! All it takes is five or more and you're on your way to the most wonderous prizes on all of Azeroth. Everybody is a winner!"
#define BARK_SILAS_DARKMOON_5	"Everyone enjoying themselves so far? That's great! Welcome to the Darkmoon Faire, the greatest show in all of Azeroth! Make sure you speak with Yebb and his friends here while you're taking in Neblegear's Darkmoon Zoo Bizarre."
#define BARK_SILAS_DARKMOON_6	"Greetings friends, and welcome to the greatest show on Azeroth!$B$BPlease, step right up and take in all we have to offer. Ride the rides and see the sights! Amaze at the wonders that the Darkmoon Faire has uncovered in this vast and mysterious world! We have spared no expense in bringing you excitement that children of all ages will delight in!"

class SilasDarkmoon : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(SilasDarkmoon)
	SilasDarkmoon(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(180000); // Start initial update after: 3mins
	}

	void AIUpdate()
	{
		switch( rand()%6 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SILAS_DARKMOON_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SILAS_DARKMOON_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SILAS_DARKMOON_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SILAS_DARKMOON_4 );
				break;
			case 4:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SILAS_DARKMOON_5 );
				break;
			case 5:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SILAS_DARKMOON_6 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 300000 + 240000 ); // Modify timer to a random value between: 3-5mins
	}
};

// Gevas Grimegate
#define BARK_GEVAS_GRIMEGATE_1	"Tickets! Redeem your Darkmoon Faire Prize Tickets here! Wondrous and exotic prizes are waiting for you!"
#define BARK_GEVAS_GRIMEGATE_2	"Five tickets or two-hundred and fifty, it doesn't matter friend, everybody is a winner!"
#define BARK_GEVAS_GRIMEGATE_3	"All it takes is five or more and you're on your way to the most wondrous prizes on all of Azeroth. Everybody is a winner!"
#define BARK_GEVAS_GRIMEGATE_4	"Mysterious prizes await the adventurous. Step right up, step right up!"

class GevasGrimegate : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(GevasGrimegate)
	GevasGrimegate(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 60000 ); // Start initial update after: 1mins
	}

	void AIUpdate()
	{
		switch( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_GEVAS_GRIMEGATE_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_GEVAS_GRIMEGATE_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_GEVAS_GRIMEGATE_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_GEVAS_GRIMEGATE_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 300000 + 180000 ); // Modify timer to a random value between: 3-5mins
	}
};

// Sylannia
#define BARK_SYLANNIA_1	"Huzzah for the tipper! Step right up and get your delicious, cold drinks right here!"
#define BARK_SYLANNIA_2	"Just in... another batch of Darkmoon Special Reserve. Come get yours before they're all gone!"
#define BARK_SYLANNIA_3	"You there! Yes you! You look thirsty. Get over here, I have just what you need!"
#define BARK_SYLANNIA_4	"Cheap beer! Get your Cheap Beer right here!"

class Sylannia : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Sylannia)
	Sylannia(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(120000); // Start initial update after: 2mins
	}

	void AIUpdate()
	{
		switch( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SYLANNIA_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SYLANNIA_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SYLANNIA_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_SYLANNIA_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 360000 + 180000 ); // Modify timer to a random value between: 3-6mins
	}
};

// Stamp Thunderhorn
#define BARK_STAMP_THUNDERHORN_1	"Darkmoon Dogs fresh off the grill. Come and get em while they're hot!"
#define BARK_STAMP_THUNDERHORN_2	"Step right up! Get your Red Hot Wings right here!"
#define BARK_STAMP_THUNDERHORN_3	"I recommend the Darkmoon Special Reserve to wash down some Red Hot Wings. And if the future is what you seek, then run, don't walk, to speak with Sayge."
#define BARK_STAMP_THUNDERHORN_4	"For a limited time only, Crunchy Frog available exclusively here at the Darkmoon Faire."
#define BARK_STAMP_THUNDERHORN_5	"You've got money and we've got food. What are you waiting for?!"

class StampThunderhorn : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(StampThunderhorn)
	StampThunderhorn(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent(180000); // Start initial update after: 3mins
	}

	void AIUpdate()
	{
		switch( rand()%5 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_STAMP_THUNDERHORN_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_STAMP_THUNDERHORN_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_STAMP_THUNDERHORN_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_STAMP_THUNDERHORN_4 );
				break;
			case 4:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_STAMP_THUNDERHORN_5 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 300000 + 180000 ); // Modify timer to a random value between: 3-5mins
	}
};

// Lhara
#define BARK_LHARA_1	"Come and take a look at my wares while you still can. We're here all week, and then we're off to some far off land."
#define BARK_LHARA_2	"Darkmoon Faire Cards? See the Professor here for those. Come see me if you are a dealer in hard to come by antiquities and artifacts."
#define BARK_LHARA_3	"Every item that I have for sale I acquired myself. You have my personal guarantee of authenticity."
#define BARK_LHARA_4	"Have you any idea what I go through to bring these incomparable valuables to sell? Come see them all for yourself!"

class Lhara : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Lhara)
	Lhara(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 90000 ); // Start initial update after: 1.5mins
	}

	void AIUpdate()
	{
		switch( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_LHARA_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_LHARA_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_LHARA_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_LHARA_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 360000 + 240000 ); // Modify timer to a random value between: 4-6mins
	}
};

// Professor Thaddeus Paleo
#define BARK_PROFESSOR_THADDEUS_PALEO_1	"If you wait to come see me, there may be nothing left!"
#define BARK_PROFESSOR_THADDEUS_PALEO_2	"Have you any Darkmoon Faire Cards? Come speak with me to learn more about them if you dare!"
#define BARK_PROFESSOR_THADDEUS_PALEO_3	"Welcome one and all to the greatest show on all of Azeroth... the Darkmoon Faire! Adventure and exitement await, don't be shy! Mysteries and prizes for both the young and the old are here for the taking. And be sure to speak with the professor about any Darkmoon Cards that you have come across during your travels!"
#define BARK_PROFESSOR_THADDEUS_PALEO_4	"Come speak with me if you are a purveyor of the unusual, or if you have any Darkmoon Faire cards."

class ProfessorThaddeusPaleo : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(ProfessorThaddeusPaleo)
	ProfessorThaddeusPaleo(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 210000 ); // Start initial update after: 3.5mins
	}

	void AIUpdate()
	{
		switch( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_PROFESSOR_THADDEUS_PALEO_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_PROFESSOR_THADDEUS_PALEO_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_PROFESSOR_THADDEUS_PALEO_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_PROFESSOR_THADDEUS_PALEO_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 180000 + 300000 ); // Modify timer to a random value between: 3-5mins
	}
};

// Darkmoon Faire Carnie
#ifdef SETUP
	#define BARK_CARNIES_1	"Faire's a coming!"
	#define BARK_CARNIES_2	"Can't you see I have work to do here?"
	#define BARK_CARNIES_3	"Won't be long now until the Darkmoon Faire opens. Come back later and check to see if we're done."
	#define BARK_CARNIES_4	"That's right friend! The Darkmoon Faire is going to be right here. Just as soon as I unload those huge wagons, put up all the tents, erect the zoo and pour the drinks. Make sure you come back!"
#else
	#define BARK_CARNIES_1	"Having a good time?"
	#define BARK_CARNIES_2	"Sure are a lot of litter bugs around here."
	#define BARK_CARNIES_3	"Don't forget to buy refreshments and souvenirs!"
	#define BARK_CARNIES_4	"The Darkmoon Faire is the greatest show on all of Azeroth!"
#endif
class Carnies : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Carnies)
	Carnies(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 120000 ); // Start initial update after: 2mins
	}

	void AIUpdate()
	{
		switch( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_CARNIES_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_CARNIES_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_CARNIES_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_CARNIES_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 300000 + 120000 ); // Modify timer to a random value between: 2-5mins
	}
};

// Flik
#define BARK_FLIK_1	"It's getting away!"
#define BARK_FLIK_2	"Get back here!"
#define BARK_FLIK_3	"Hey, someone help me catch this thing!"
#define BARK_FLIK_4	"Frogs and leather balls for sale!"

class Flik : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Flik)
	Flik(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 180000 ); // Start initial update after: 3mins
	}

	void AIUpdate()
	{
		switch ( rand()%4 )
		{
			case 0:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_FLIK_1 );
				break;
			case 1:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_FLIK_2 );
				break;
			case 2:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_FLIK_3 );
				break;
			case 3:
				GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_FLIK_4 );
				break;
		}
		ModifyAIUpdateEvent( rand() % 240000 + 120000 ); // Modify timer to a random value between: 2-4mins
	}
};

// Morja
#define BARK_MORJA_1	"Jubjub? Where are you, Jubjub? Oh no! Where did you go this time!"

class Morja : public CreatureAIScript
{
public:
	ADD_CREATURE_FACTORY_FUNCTION(Morja)
	Morja(Creature *pCreature) : CreatureAIScript(pCreature)
	{
		RegisterAIUpdateEvent( 240000 ); // Start initial update after: 4mins
	}

	void AIUpdate()
	{
		GetUnit()->SendChatMessage( CHAT_MSG_MONSTER_SAY, LANG_UNIVERSAL, BARK_MORJA_1 );
		ModifyAIUpdateEvent( rand() % 360000 + 240000 ); // Modify timer to a random value between: 4-6mins
	}
};

void SetupDarkmoonFaireCreatures(ScriptMgr * mgr)
{
	mgr->register_creature_script( 14822, &Sayge::Create );						// Sayge
	mgr->register_creature_script( 14823, &SilasDarkmoon::Create );				// Silas Darkmoon
	mgr->register_creature_script( 14828, &GevasGrimegate::Create );			// Gevas Grimegate
	mgr->register_creature_script( 14844, &Sylannia::Create );					// Sylannia
	mgr->register_creature_script( 14845, &StampThunderhorn::Create );			// StampThunderhorn
	mgr->register_creature_script( 14846, &Lhara::Create );						// Lhara
	mgr->register_creature_script( 14847, &ProfessorThaddeusPaleo::Create );	// Professor Thaddeus Paleo
	mgr->register_creature_script( 14849, &Carnies::Create );					// Darkmoon Faire Carnie
	mgr->register_creature_script( 14860, &Flik::Create );						// Flik
	mgr->register_creature_script( 14871, &Morja::Create );						// Morja
}