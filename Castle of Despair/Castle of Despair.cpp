/* Castle of Despair
   SDH 1/21/03 */

#include "stdafx.h"
#include "windows.h"

#include <cstdlib>
#include <conio.h>
#include <iostream>
#include <string>
#include <time.h>
#include <vector>

using namespace std;

int random(int max)
{
    return rand() % max;
}

void randomize(void)
{
    srand (time(NULL));
}

struct MatrixType
{
    MatrixType();
    char Space[8][8];
};
MatrixType::MatrixType()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            Space[i][j] = '.';
        }
    }
}

typedef vector<MatrixType> FloorType;

struct StatsType
{
    string Race;
    string Gender;
    int Attack;
    int Defense;
    int Health;
    int Magic;
    int Dex;
    int Gold;
    int Immobilize;
    bool Blind;
    bool Book;
    bool Runestaff;
    string WeaponName;
    int WeaponAttack;
    string ArmorName;
    int ArmorDefense;
    bool Dead;
};

struct PosType
{
    int t;
    int x;
    int y;
    int z;
};

struct TreasureType
{
    bool BlueFlame;
    bool RubyRed;
    bool GreenGem;
    bool OminousGlobe;
    bool OpalEye;
    bool NornStone;
    bool Palantir;
    bool PalePearl;
    bool Silmaril;
};

struct MonsterType
{
    string Name;
    int Health;
    int Attack;
    int Defense;
    int Dex;
    int Magic;
    int Bribe;
    int Immobilize;
    bool Dead;
};

void Intro()
{
    cout << "*******************************************************************************" << endl;
    cout << "                              Castle of Despair                                " << endl;
    cout << "*******************************************************************************" << endl;
    cout << endl;
    cout << endl;
    cout << "          A long time ago, a wizard by the name of Barbarus built a" << endl;
    cout << "          castle in the land of N'ruk. He ruled the surrounding area" << endl;
    cout << "          with an iron fist his entire life. Soon the castle only" << endl;
    cout << "          became known as the Castle of Despair. When he died, he" << endl;
    cout << "          left his castle full of treasure and demons." << endl;
    cout << endl;
    cout << "          The castle still stands a century later. Now you are one" << endl;
    cout << "          of the brave explorers who venture into the castle in" << endl;
    cout << "          search of the greatest treasure Barbarus was said to have" << endl;
    cout << "          left: the Ominous Globe. So far, many have entered the" << endl;
    cout << "          castle, but none have returned..." << endl;
    cout << endl;
    cout << endl;
}

void GetStartStats(StatsType &Stats, char &Race, char &Gender)
{
    cout << "All right, bold one." << endl;
    cout << endl;

    while (true)
    {
        cout << "Which race are you (Elf, Dwarf, Man, Hobbit)? ";
        cin >> Race;
        if ( (Race == 'E' || Race == 'e') ||
             (Race == 'D' || Race == 'd') ||
             (Race == 'M' || Race == 'm') ||
             (Race == 'H' || Race == 'h') )
        {
            break;
        }
        cout << "Ha!" << endl;
    }

    if (Race == 'E' || Race == 'e')
    {
        Stats.Race = "Elf";
    }
    if (Race == 'D' || Race == 'd')
    {
        Stats.Race = "Dwarf";
    }
    if (Race == 'M' || Race == 'm')
    {
        Stats.Race = "Man";
    }
    if (Race == 'H' || Race == 'h')
    {
        Stats.Race = "Hobbit";
    }

    cout << endl;
    while (true)
    {
        cout << "What gender are you? ";
        cin >> Gender;
        if ( (Gender == 'M' || Gender == 'm') ||
             (Gender == 'F' || Gender == 'f') )
        {
            break;
        }
        cout << "I don\'t believe you!" << endl;
    }

    if (Gender == 'M' || Gender == 'm')
    {
        Stats.Gender = "male"; 
    }
    if (Gender == 'F' || Gender == 'f')
    {
        Stats.Gender = "female";
    }

    cout << endl;

    if (Race == 'E' || Race == 'e')
    {
        Stats.Attack  = 8;
        Stats.Defense = 8;
        Stats.Magic   = 10;
        Stats.Dex     = 14;
    }
    if (Race == 'D' || Race == 'd')
    {
        Stats.Attack  = 16;
        Stats.Defense = 10;
        Stats.Magic   = 6;
        Stats.Dex     = 8;
    }
    if (Race == 'M' || Race == 'm')
    {
        Stats.Attack  = 10;
        Stats.Defense = 10;
        Stats.Magic   = 10;
        Stats.Dex     = 10;
    }
    if (Race == 'H' || Race == 'h')
    {
        Stats.Attack  = 8;
        Stats.Defense = 9;
        Stats.Magic   = 10;
        Stats.Dex     = 13;
    }

    Stats.Health = 20;
}

void StartEquip(StatsType &Stats)
{
    char Choice;
    while (true)
    {
        cout << "You have " << Stats.Gold << " gold and " << Stats.WeaponName << "." << endl;
        cout << "<25> Dagger   <10> Knife   <0> Nothing" << endl;
        cout << "What do you want? ";
        cin >> Choice;
        if ( (Choice == 'D' || Choice == 'd') ||
             (Choice == 'K' || Choice == 'k') ||
             (Choice == 'N' || Choice == 'n') )
        {
            break;
        }
        cout << "I don\'t see that one!" << endl;
    }
    cout << endl;
    
    if (Choice == 'D' || Choice == 'd')
    {
        Stats.WeaponName = "a Dagger";
        Stats.WeaponAttack = 10;
        Stats.Attack += Stats.WeaponAttack;
        Stats.Gold -= 25;
    }
    if (Choice == 'K' || Choice == 'k')
    {
        Stats.WeaponName = "a Knife";
        Stats.WeaponAttack = 5;
        Stats.Attack += Stats.WeaponAttack;
        Stats.Gold -= 10;
    }
    if (Choice == 'N' || Choice == 'n')
    {
        Stats.WeaponName = "no weapon";
        Stats.WeaponAttack = 0;
        Stats.Attack += Stats.WeaponAttack;
    }

    while (true)
    {
        cout << "You have " << Stats.Gold << " gold and " << Stats.ArmorName << "." << endl;
        cout << "<25> Plate   <10> Cloth   <0> Nothing" << endl;
        cout << "What do you want? ";
        cin >> Choice;
        if ( (Choice == 'P' || Choice == 'p') ||
             (Choice == 'C' || Choice == 'c') ||
             (Choice == 'N' || Choice == 'n') )
        {
            break;
        }

        cout << "Where\'s that choice?" << endl;
    }
    cout << endl;

    if (Choice == 'P' || Choice == 'p')
    {
        Stats.ArmorName = "Plate armor";
        Stats.ArmorDefense = 10;
        Stats.Defense += Stats.ArmorDefense;
        Stats.Gold -= 25;
    }
    if (Choice == 'C' || Choice == 'c')
    {
        Stats.ArmorName = "Cloth armor";
        Stats.ArmorDefense = 5;
        Stats.Defense += Stats.ArmorDefense;
        Stats.Gold -= 10;
    }
    if (Choice == 'N' || Choice == 'n')
    {
        Stats.ArmorName = "no armor";
        Stats.ArmorDefense = 0;
        Stats.Defense += Stats.ArmorDefense;
    }
}

void StockCastle(FloorType &Floor)
{
    const int MaxFloorNum = 7;
    int FloorNum;

    Floor[0].Space[0][0] = 'E';

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Monsters = (random(3) + 9);
        while (Monsters > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'M';
                Monsters--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Warps = (random(3) + 2);
        while (Warps > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'W';
                Warps--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Pools = (random(3) + 2);
        while (Pools > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'P';
                Pools--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Chests = (random(3) + 6);
        while (Chests > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'C';
                Chests--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Books = (random(3) + 6);
        while (Books > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'B';
                Books--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Orbs = (random(3) + 2);
        while (Orbs > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'O';
                Orbs--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Sinkholes = (random(3) + 4);
        while (Sinkholes > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'S';
                Sinkholes--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Gold = (random(3) + 4);
        while (Gold > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'G';
                Gold--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int Vendor = (random(2) + 1);
        while (Vendor > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'V';
                Vendor--;
            }
        }
    }

    for (FloorNum = 0; FloorNum <= MaxFloorNum; FloorNum++)
    {
        int UStairs = (random(2) + 1);
        if (FloorNum == 7)
        {
            UStairs = 1;
        }
        while (UStairs > 0)
        {
            int RandNum1 = random(8);
            int RandNum2 = random(8);

            if (Floor[FloorNum].Space[RandNum1][RandNum2] == '.')
            {
                Floor[FloorNum].Space[RandNum1][RandNum2] = 'U';
                UStairs--;
                if (FloorNum < MaxFloorNum)
                {
                    Floor[FloorNum + 1].Space[RandNum1][RandNum2] = 'D';
                }
            }
        }
    }
}

void DispFloor(const FloorType Floor, PosType Position)
{
    const int FloorNum = Position.z;
    for (int Row = 0; Row <= 7; Row++)
    {
        for (int Col = 0; Col <=7; Col++)
        {
            if (Position.x == Row && Position.y == Col)
            {
                cout << "<" << Floor [FloorNum].Space[Row][Col];
                cout << "> ";
            }
            else
            {
                cout << " " << Floor[FloorNum].Space[Row][Col];
                cout << "  ";
            }
        }
        cout << endl << endl;
    }

    cout << "You are at (" << Position.x << "," << Position.y << ")";
    cout << ", Floor " << Position.z << endl;
}

void DispStats(StatsType Stats, TreasureType Treasures)
{
    cout << "You are a " << Stats.Gender << " "<< Stats.Race;
    cout << " with:" << endl;

    const int NumWidth = 2;
    const int ColWidth = 16;

    cout.setf(ios::left);

    cout.width(NumWidth); cout << Stats.Health << " ";
    cout.width(ColWidth); cout << "Health";
    cout.width(NumWidth); cout << Stats.Gold << " ";
    cout.width(ColWidth); cout << "Gold";
    cout << endl;

    cout.width(NumWidth); cout << Stats.Attack << " ";
    cout.width(ColWidth); cout << "Attack";
    cout.width(NumWidth); cout << Stats.Defense << " ";
    cout.width(ColWidth); cout << "Defense";
    cout << endl;

    cout.width(NumWidth); cout << Stats.Dex << " ";
    cout.width(ColWidth); cout << "Dexterity";
    cout.width(NumWidth); cout << Stats.Magic << " ";
    cout.width(ColWidth); cout << "Magic";
    cout << endl;

    cout.width(NumWidth); cout << "" << " ";
    cout.width(ColWidth); cout << Stats.WeaponName;
    cout.width(NumWidth); cout << "" << " ";
    cout.width(ColWidth); cout << Stats.ArmorName;
    cout << endl;

    if (Treasures.BlueFlame == true)
    {
        cout << " The Blue Flame  ";
    }
    if (Treasures.GreenGem == true)
    {
        cout << " The Green Gem  ";
    }
    if (Treasures.NornStone == true)
    {
        cout << " The Norn Stone  ";
    }
    if (Treasures.OpalEye == true)
    {
        cout << " The Opal Eye";
    }

    cout << endl;

    if (Treasures.Palantir == true)
    {
        cout << " The Palantir  ";
    }
    if (Treasures.PalePearl == true)
    {
        cout << " The Pale Pearl  ";
    }
    if (Treasures.RubyRed == true)
    {
        cout << " The Ruby Red  ";
    }
    if (Treasures.Silmaril == true)
    {
        cout << " The Silmaril  ";
    }

    cout << endl;
}

char GetCommand(StatsType Stats)
{
    char Command;
    do
    {
        cout << "What do you want to do? ";
        cin >> Command;
        if ( (Command != 'H' && Command != 'h') && (Command != 'N' && Command != 'n') &&
             (Command != 'S' && Command != 's') && (Command != 'E' && Command != 'e') &&
             (Command != 'W' && Command != 'w') && (Command != 'D' && Command != 'd') &&
             (Command != 'U' && Command != 'u') && (Command != 'R' && Command != 'r') &&
             (Command != 'O' && Command != 'o') && (Command != 'G' && Command != 'g') &&
             (Command != 'T' && Command != 't') && (Command != 'Q' && Command != 'q') )
        {
            cout << "Silly " << Stats.Race;
            cout << ", that\'s not a command!" << endl;
        }
    } while ( (Command != 'H' && Command != 'h') && (Command != 'N' && Command != 'n') &&
              (Command != 'S' && Command != 's') && (Command != 'E' && Command != 'e') &&
              (Command != 'W' && Command != 'w') && (Command != 'D' && Command != 'd') &&
              (Command != 'U' && Command != 'u') && (Command != 'R' && Command != 'r') &&
              (Command != 'O' && Command != 'o') && (Command != 'G' && Command != 'g') &&
              (Command != 'T' && Command != 't') && (Command != 'Q' && Command != 'q') );

    return Command;
}

void InsertBreak()
{
    cout << "Press any key to continue" << endl;
    getch();
    cout << endl;
}

void Help()
{
    cout << "The following commands are available:" << endl;
    cout << endl;
    cout << "H/elp    N/orth    S/outh    E/ast    W/est" << endl;
    cout << "D/own    U/p       O/pen     G/aze    T/eleport" << endl;
    cout << "DR/ink   Q/uit" << endl;
    cout << endl;
    cout << "The contents of rooms are:" << endl;
    cout << endl;
    cout << ". = Empty Room    B = Book          C = Chest" << endl;
    cout << "D = Stairs Down   E = Entrance      G = Gold" << endl;
    cout << "M = Monster       O = Crystal Orb   P = Magic Pool" << endl;
    cout << "S = Sinkhole      T = Treasure      U = Stairs Up" << endl;
    cout << "V = Vendor        W = Warp" << endl;
    cout << endl;
    cout << "The benefits of having treasures:" << endl;
    cout << endl;
    cout << "Ruby Red - Fire Spell          Pale Pearl - Web Spell" << endl;
    cout << "Green Gem - Lightning Spell    Opal Eye - Cures Blindness" << endl;
    cout << "Blue Flame - Dissolves Book    Norn Stone - Critical Attacks" << endl;
    cout << "Palantir - Death Spell         Silmaril - Heal Spell" << endl;
    cout << endl;
    cout << endl;
    cout << endl;
    InsertBreak();
}

void North(PosType &Position)
{
    if (Position.x > 0)
    {
        Position.x -= 1;
    }
    else if (Position.x == 0)
    {
        Position.x = 7;
    }
}

void South(PosType &Position)
{
    if (Position.x < 7)
    {
        Position.x += 1;
    }
    else if (Position.x == 7)
    {
        Position.x = 0;
    }
}

void East(PosType &Position)
{
    if (Position.y < 7)
    {
        Position.y += 1;
    }
    else if (Position.y == 7)
    {
        Position.y = 0;
    }
}

void West(PosType &Position)
{
    if (Position.y > 0)
    {
        Position.y -= 1;
    }
    else if (Position.y == 0)
    {
        Position.y = 7;
    }
}

void OpenChest(StatsType &Stats, PosType &Position, FloorType &Floor)
{
    cout << endl;

    if (Floor[Position.z].Space[Position.x][Position.y] == 'C')
    {
        int RandNum = random(100) + 1;

        if (RandNum <= 20)
        {
            cout << "Toxic gas fills the air - you stagger to the closest exit!" << endl;
            int PosX = Position.x;
            int PosY = Position.y;
            int PosZ = Position.z;
            int RandDir = random(4);
            if (RandDir == 0)
            {
                North(Position);
            }
            if (RandDir == 1)
            {
                South(Position);
            }
            if (RandDir == 2)
            {
                East(Position);
            }
            if (RandDir == 3)
            {
                West(Position);
            }
            Floor[PosZ].Space[PosX][PosY] = '.';
        }

        if (RandNum > 20 && RandNum <= 40)
        {
            cout << "KABOOM!!! The chest explodes!" << endl;
            Stats.Health -= 2;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 40 && RandNum <= 50)
        {
            cout << "There is nothing in this chest except cobwebs." << endl;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 50 && RandNum <= 65)
        {
            int Weight = random(3);
            int GoldAmount;
            if (Weight == 0 || Weight == 1)
            {
                GoldAmount = random(500) + 1;
            }
            if (Weight == 2)
            {
                GoldAmount = random(500) + 501;
            }
            Stats.Gold += GoldAmount;
            cout << "You get " << GoldAmount << " gold from the chest." << endl;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 65 && RandNum <= 75)
        {
            cout << "You found a Health Potion - you feel a little healthier." << endl;
            Stats.Health += 5;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 75 && RandNum <= 85)
        {
            cout << "You found a Magic Potion - you can feel your fingers tingle." << endl;
            Stats.Magic += 5;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 85 && RandNum <= 95)
        {
            cout << "You found a Dexterity Potion - your feet feel lighter already." << endl;
            Stats.Dex += 5;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 95)
        {
            cout << "FLASH!!! There is a sudden white light, causing you to go blind." << endl;
            Stats.Blind = true;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }
    }
    cout << endl;
    InsertBreak();
}

void OpenBook(StatsType &Stats, PosType &Position, FloorType &Floor)
{
    cout << endl;
    if (Floor[Position.z].Space[Position.x][Position.y] == 'B')
    {
        int RandNum = random(100) + 1;

        if (RandNum <= 20)
        {
            cout << "It\'s just a blank copy." << endl;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 20 && RandNum <= 35)
        {
            cout << "It\'s a spellbook - you gain ancient magic from it." << endl;
            Stats.Magic += 5;
            Floor[Position.z].Space[Position.x][Position.y] = '.';;
        }

        if (RandNum > 35 && RandNum <= 50)
        {
            cout << "It turns out to be a manual on how to sharpen your weapons." << endl;
            Stats.Attack += 5;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 50 && RandNum <= 65)
        {
            cout << "The book is an armor-hardening guide." << endl;
            Stats.Defense += 5;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 65 && RandNum <= 85)
        {
            cout << "Poetry of a modern kind can be found in this book of ancient bind." << endl;
                Floor[Position.z].Space[Position.x][Position.y] = '.';
        }

        if (RandNum > 85)
        {
            cout << "The book sticks to your hands! Now you are unable to draw your weapon!" << endl;
            Stats.Book = true;
            Floor[Position.z].Space[Position.x][Position.y] = '.';
        }
    }
    cout << endl;
    InsertBreak();
}

void Gaze(FloorType Floor, StatsType &Stats)
{
    int RandNum = random(100) + 1;

    cout << endl;

    if (RandNum <= 25)
    {
        int RandX = random(8);
        int RandY = random(8);
        int RandZ = random(8);
        char SpaceChar = Floor[RandZ].Space[RandX][RandY];
        cout << "You will fine ";
        switch (SpaceChar)
        {
            case '.': cout << "an empty room ";         break;
            case 'E': cout << "the entrance ";          break;
            case 'M': cout << "a monster ";             break;
            case 'W': cout << "a warp ";                break;
            case 'P': cout << "a magical pool ";        break;
            case 'C': cout << "a chest ";               break;
            case 'B': cout << "a book ";                break;
            case 'O': cout << "a crystal orb ";         break;
            case 'S': cout << "a sinkhole ";            break;
            case 'G': cout << "some gold ";             break;
            case 'V': cout << "a vendor ";              break;
            case 'U': cout << "stairs leading up ";     break;
            case 'D': cout << "stairs leading down ";   break;
        }
        cout << "at (" << RandX << "," << RandY << ") Floor " << RandZ << endl;
    }

    if (RandNum > 25 && RandNum <=45)
    {
        cout << "You see yourself in a bloody heap!" << endl;
        Stats.Health -= 2;
    }

    if (RandNum > 45 && RandNum <= 70)
    {
        cout << "You see a";
        int RandMonster = random(13);
        switch (RandMonster)
        {
            case 0: cout << "n ogre ";      break;
            case 1: cout << " wolf ";       break;
            case 2: cout << " kobold ";     break;
            case 3: cout << " dragon ";     break;
            case 4: cout << " gargoyle ";   break;
            case 5: cout << " goblin ";     break;
            case 6: cout << " vendor ";     break;
            case 7: cout << " lion ";       break;
            case 8: cout << " troll ";      break;
            case 9: cout << " bear ";       break;
            case 10: cout << " minotaur ";  break;
            case 11: cout << " chimera ";   break;
            case 12: cout << " balrog ";    break;
        }
        cout << "looking back at you." << endl;
    }

    if (RandNum > 70)
    {
        cout << "You see yourself drinking from a pool and becoming a";
        int RandMonster = random(13);
        switch (RandMonster)
        {
            case 0: cout << "n ogre ";      break;
            case 1: cout << " wolf ";       break;
            case 2: cout << " kobold ";     break;
            case 3: cout << " dragon ";     break;
            case 4: cout << " gargoyle ";   break;
            case 5: cout << " goblin ";     break;
            case 6: cout << " vendor ";     break;
            case 7: cout << " lion ";       break;
            case 8: cout << " troll ";      break;
            case 9: cout << " bear ";       break;
            case 10: cout << " minotaur ";  break;
            case 11: cout << " chimera ";   break;
            case 12: cout << " balrog ";    break;
        }
        cout << "." << endl;
    }
    cout << endl;
    InsertBreak();
}

void Teleport(PosType &Position, StatsType Stats)
{
    cout << endl;
    int XCoor, YCoor, ZCoor;
    bool Break;
    do
    {
        cout << "Enter the X-coordinate: ";
        cin >> XCoor;
        cout << "Enter the Y-coordinate: ";
        cin >> YCoor;
        cout << "Enter the Z-coordinate: ";
        cin >> ZCoor;

        if ( (XCoor < 0 || XCoor > 7) ||
             (YCoor < 0 || YCoor > 7) ||
             (ZCoor < 0 || ZCoor > 7) )
        {
            cout << "Try entering a number between 0 and 7, stupid " << Stats.Race << "." << endl;
            Break = false;
        }
        else
        {
            Break = true;
        }
    } while (Break == false);

    Position.x = XCoor;
    Position.y = YCoor;
    Position.z = ZCoor;
}

void Drink(StatsType &Stats)
{
    int RandNum = random(100) + 1;

    cout << endl;
    cout << "You drink from the pool and ";

    if (RandNum <= 10)
    {
        cout << "you changed into a ";
        if (Stats.Gender == "male")
        {
            Stats.Gender = "female";
        }
        else
        {
            Stats.Gender = "male";
        }
        cout << Stats.Gender << "!" << endl;
    }

    if (RandNum > 10 && RandNum <= 20)
    {
        cout << "you changed into a ";
        int RandRace = random(3);
        if (Stats.Race == "Elf")
        {
            if (RandRace == 0)
            {
                Stats.Race = "Dwarf";
            }
            if (RandRace == 1)
            {
                Stats.Race = "Man";
            }
            if (RandRace == 2)
            {
                Stats.Race = "Hobbit";
            }
        }

        if (Stats.Race == "Dwarf")
        {
            if (RandRace == 0)
            {
                Stats.Race = "Elf";
            }
            if (RandRace == 1)
            {
                Stats.Race = "Man";
            }
            if (RandRace == 2)
            {
                Stats.Race = "Hobbit";
            }
        }

        if (Stats.Race == "Man")
        {
            if (RandRace == 0)
            {
                Stats.Race = "Elf";
            }
            if (RandRace == 1)
            {
                Stats.Race = "Dwarf";
            }
            if (RandRace == 2)
            {
                Stats.Race = "Hobbit";
            }
        }

        if (Stats.Race == "Hobbit")
        {
            if (RandRace == 0)
            {
                Stats.Race = "Elf";
            }
            if (RandRace == 1)
            {
                Stats.Race = "Dwarf";
            }
            if (RandRace == 2)
            {
                Stats.Race = "Man";
            }
        }

        cout << Stats.Race << "!" << endl;
    }

    if (RandNum > 20 && RandNum <= 50)
    {
        int RandPM = random(2);
        if (RandPM == 0)
        {
            Stats.Dex += 2;
            cout << "feel nimbler!" << endl;
        }
        if (RandPM == 1)
        {
            Stats.Dex -= 2;
            cout << "feel slower!" << endl;
        }
    }

    if (RandNum > 50 && RandNum <= 80)
    {
        int RandPM = random(2);
        if (RandPM == 0)
        {
            Stats.Magic += 2;
            cout << "feel magical!" << endl;
        }
        if (RandPM == 1)
        {
            Stats.Magic -= 2;
            cout << "feel less magical!" << endl;
        }
    }

    if (RandNum > 80)
    {
        cout << "feel refreshed!" << endl;
    }

    cout << endl;
    InsertBreak();
}

void Died(StatsType Stats, PosType Position, TreasureType Treasure)
{
    cout << "You died due to lack of health!" << endl;
    cout << "When you died you had: " << endl;

    if (Treasure.RubyRed == true)
    {
        cout << "   Ruby Red" << endl;
    }
    if (Treasure.GreenGem == true)
    {
        cout << "   Green Gem" << endl;
    }
    if (Treasure.BlueFlame == true)
    {
        cout << "   Blue Flame" << endl;
    }
    if (Treasure.Palantir == true)
    {
        cout << "   Palantir" << endl;
    }
    if (Treasure.PalePearl == true)
    {
        cout << "   Pale Pearl" << endl;
    }
    if (Treasure.OpalEye == true)
    {
        cout << "   Opal Eye" << endl;
    }
    if (Treasure.NornStone == true)
    {
        cout << "   Norn Stone" << endl;
    }
    if (Treasure.Silmaril == true)
    {
        cout << "   Silmaril" << endl;
    }
    
    cout << Stats.ArmorName << endl;
    cout << Stats.WeaponName << endl;
}

bool QuitGame(StatsType Stats)
{
    char Quit;
    cout << endl;
    cout << "Do you really want to quit (Y/N)? ";
    cin >> Quit;
    cout << endl;

    if (Quit == 'Y' || Quit == 'y')
    {
        cout << "Maybe the dumb " << Stats.Race << " is not so dumb after all!" << endl;
        cout << endl;
        InsertBreak();
        return(true);
    }
    else
    {
        cout << "Then don\'t say you do!" << endl;
        cout << endl;
        InsertBreak();
        return(false);
    }
}

void PickMonster(MonsterType &Monster)
{
    int RandNum = random(13);
    switch (RandNum)
    {
        case 0:
        {
            Monster.Name = "ogre";
            Monster.Health = 28;
            Monster.Attack = 20;
            Monster.Defense = 14;
            Monster.Dex = 10;
            Monster.Magic = 0;
            Monster.Bribe = 200;
            break;
        }

        case 1:
        {
            Monster.Name = "wolf";
            Monster.Health = 24;
            Monster.Attack = 18;
            Monster.Defense = 16;
            Monster.Dex = 20;
            Monster.Magic = 0;
            Monster.Bribe = 0;
            break;
        }

        case 2:
        {
            Monster.Name = "kobold";
            Monster.Health = 22;
            Monster.Attack = 17;
            Monster.Defense = 16;
            Monster.Dex = 16;
            Monster.Magic = 16;
            Monster.Bribe = 100;
            break;
        }

        case 3:
        {
            Monster.Name = "dragon";
            Monster.Health = 30;
            Monster.Attack = 30;
            Monster.Defense = 30;
            Monster.Dex = 12;
            Monster.Magic = 25;
            Monster.Bribe = 300;
            break;
        }

        case 4:
        {
            Monster.Name = "gargoyle";
            Monster.Health = 25;
            Monster.Attack = 15;
            Monster.Defense = 26;
            Monster.Dex = 10;
            Monster.Magic = 20;
            Monster.Bribe = 200;
            break;
        }

        case 5:
        {
            Monster.Name = "goblin";
            Monster.Health = 20;
            Monster.Attack = 18;
            Monster.Defense = 16;
            Monster.Dex = 16;
            Monster.Magic = 14;
            Monster.Bribe = 300;
            break;
        }

        case 6:
        {
            Monster.Name = "vendor";
            Monster.Health = 25;
            Monster.Attack = 20;
            Monster.Defense = 20;
            Monster.Dex = 20;
            Monster.Magic = 20;
            Monster.Bribe = 0;
            break;
        }

        case 7:
        {
            Monster.Name = "lion";
            Monster.Health = 24;
            Monster.Attack = 20;
            Monster.Defense = 14;
            Monster.Dex = 18;
            Monster.Magic = 0;
            Monster.Bribe = 0;
            break;
        }

        case 8:
        {
            Monster.Name = "troll";
            Monster.Health = 30;
            Monster.Attack = 25;
            Monster.Defense = 20;
            Monster.Dex = 12;
            Monster.Magic = 10;
            Monster.Bribe = 0;
            break;
        }

        case 9:
        {
            Monster.Name = "bear";
            Monster.Health = 25;
            Monster.Attack = 20;
            Monster.Defense = 12;
            Monster.Dex = 12;
            Monster.Magic = 0;
            Monster.Bribe = 0;
            break;
        }

        case 10:
        {
            Monster.Name = "minotaur";
            Monster.Health = 30;
            Monster.Attack = 22;
            Monster.Defense = 20;
            Monster.Dex = 10;
            Monster.Magic = 0;
            Monster.Bribe = 0;
            break;
        }

        case 11:
        {
            Monster.Name = "chimera";
            Monster.Health = 20;
            Monster.Attack = 18;
            Monster.Defense = 18;
            Monster.Dex = 16;
            Monster.Magic = 20;
            Monster.Bribe = 250;
            break;
        }

        case 12:
        {
            Monster.Name = "balrog";
            Monster.Health = 30;
            Monster.Attack = 26;
            Monster.Defense = 20;
            Monster.Dex = 16;
            Monster.Magic = 25;
            Monster.Bribe = 300;
            break;
        }
    }
}

void PlayerMove(StatsType &Stats, PosType &Position, TreasureType &Treasure, MonsterType &Monster, bool &BattleContinue)
{
    cout << "You can:" << endl;
    cout << "   Attack" << endl;
    cout << "   Retreat" << endl;
    if (Monster.Bribe > 0)
    {
        cout << "   Bribe" << endl;
    }
    if ( (Stats.Magic >= 2) && (Treasure.RubyRed == true) )
    {
        cout << "   Cast a Spell" << endl;
    }
    cout << endl;

    char Command;
    do
    {
        cout << "What do you want to do? ";
        cin >> Command;
        if ( (Command != 'A') && (Command != 'a') &&
             (Command != 'R') && (Command != 'r') &&
             (Command != 'B') && (Command != 'b') &&
             (Command != 'S') && (Command != 's') )
        {
            cout << "You can\'t do that!" << endl;
        }
    } while ( (Command != 'A') && (Command != 'a') &&
              (Command != 'R') && (Command != 'r') &&
              (Command != 'B') && (Command != 'b') &&
              (Command != 'S') && (Command != 's') );

    if (Command == 'A' || Command == 'a')
    {
        int Damage = Stats.Attack - (Monster.Defense * 0.5);
        if (Damage < 1)
        {
            Damage = 1;
        }
        int HitProb = random(21) + 1;
        if (HitProb >= Monster.Dex)
        {
            cout << "You attacked the monster and did " << Damage << " damage." << endl;
            Monster.Health -= Damage;
        }
        else
        {
            cout << "You swung at the " << Monster.Name << " but missed." << endl;
        }
    }

    if (Command == 'R' || Command == 'r')
    {
        int EscapeProb = Monster.Dex;
        int Escape = random(100) + 1;
        if (Escape >= EscapeProb)
        {
            cout << "The " << Monster.Name << " blocked your escape!" << endl;
        }
        else
        {
            BattleContinue = false;
            char RunDir;
            do
            {
                cout << "Which way do you want to run? ";
                cin >> RunDir;
                if ( (RunDir != 'N' && RunDir != 'n') &&
                     (RunDir != 'S' && RunDir != 's') &&
                     (RunDir != 'E' && RunDir != 'e') &&
                     (RunDir != 'W' && RunDir != 'w') )
                {
                    cout << "Enter a real direction!" << endl;
                }
            } while ( (RunDir != 'N' && RunDir != 'n') &&
                      (RunDir != 'S' && RunDir != 's') &&
                      (RunDir != 'E' && RunDir != 'e') &&
                      (RunDir != 'W' && RunDir != 'w') );
            cout << "You ran from battle!" << endl;
        }
    }

    if ( (Command == 'B' || Command == 'b') && (Monster.Bribe == 0) )
    {
        cout << endl;
        cout << "You can\'t bribe this monster!" << endl;
        cout << endl;
    }

    if ( (Command == 'B' || Command == 'b') && (Monster.Bribe > 0) )
    {
        char GiveBribe;
        cout << endl;
        cout << "The monster demands " << Monster.Bribe;
        cout << " gold pieces." << endl;
        cout << "Give it to him? ";
        cin >> GiveBribe;
        if (GiveBribe == 'Y' || GiveBribe == 'y')
        {
            if (Stats.Gold < Monster.Bribe)
            {
                cout << "You don\'t have that much money!" << endl;
                cout << "The monster is enraged that you can\'t give it the money!" << endl;
            }
            else
            {
                cout << "You wisely gave the " << Monster.Name << " the money and it became docile." << endl;
                Stats.Gold -= Monster.Bribe;
                BattleContinue = false;
            }
        }
        else
        {
            cout << "The monster is enraged that you would not give it the money!" << endl;
        }
    }

    if (Command == 'S' || Command == 's')
    {
        cout << "You can use the following spells:" << endl;
        if (Treasure.RubyRed == true)
        {
            cout << "   Fireball" << endl;
        }
        if (Treasure.GreenGem == true)
        {
            cout << "   Thunderbolt" << endl;
        }
        if ( (Stats.Magic >= 3) && (Treasure.PalePearl == true) )
        {
            cout << "   Web" << endl;
        }
        if ( (Stats.Magic >= 5) && (Treasure.Silmaril== true) )
        {
            cout << "   Heal" << endl;
        }
        if ( (Stats.Magic >= 8) && (Treasure.Palantir == true) )
        {
            cout << "   Deathspell" << endl;
        }

        char Spell;
        do
        {
            cout << "Which spell do you want to use? ";
            cin >> Spell;
            if ( (Spell != 'F' && Spell != 'f') &&
                 (Spell != 'T' && Spell != 't') &&
                 (Spell != 'W' && Spell != 'w') &&
                 (Spell != 'H' && Spell != 'h') &&
                 (Spell != 'D' && Spell != 'D') )
            {
                cout << "You don\'t have that spell!" << endl;
            }
        } while ( (Spell != 'F' && Spell != 'f') &&
                  (Spell != 'T' && Spell != 't') &&
                  (Spell != 'W' && Spell != 'w') &&
                  (Spell != 'H' && Spell != 'h') &&
                  (Spell != 'D' && Spell != 'D') );

        int SpellDamage = 0;
        bool SpellUsed = false;

        if ( (Spell == 'F' || Spell == 'f') && (Stats.Magic >= 2) )
        {
            cout << "You sent a fireball from heaven onto the ";
            cout << Monster.Name << "!" << endl;
            SpellDamage = 10;
            cout << "You caused " << SpellDamage << " damage!" << endl;
            Stats.Magic -= 2;
            SpellUsed = true;
        }
        if ( (Spell == 'T' || Spell == 't') && (Stats.Magic >= 2) )
        {
            cout << "You called down lightning from the sky";
            int HitProb = random(10);
            if (HitProb == 1)
            {
                cout << ", but it missed!" << endl;
                SpellDamage = 0;
            }
            else
            {
                cout << " and electrified the " << Monster.Name << "!" << endl;
                SpellDamage = random(3) + 10;
                cout << "You caused " << SpellDamage << " damage!" << endl;
            }
            Stats.Magic -= 2;
            SpellUsed = true;
        }
        if ( (Spell == 'W' || Spell == 'w') && (Stats.Magic >= 3) )
        {
            cout << "You shot out a web and immobilized the " << Monster.Name << "!" << endl;
            Monster.Immobilize = 3;
            Stats.Magic -= 3;
            SpellUsed = true;
        }
        if ( (Spell == 'H' || Spell == 'h') && (Stats.Magic >= 5) )
        {
            cout << "You cast the Heal spell on yourself ";
            int HealAmount = random(3) + 4;
            cout << "and gained " << HealAmount << " health!" << endl;
            Stats.Health += HealAmount;
            Stats.Magic -= 5;
            SpellUsed = true;
        }
        if ( (Spell == 'D' || Spell == 'd') && (Stats.Magic >= 8) )
        {
            cout << "You cast the Death spell on the " << Monster.Name;
            cout << " and it dropped dead at your feet!" << endl;
            Monster.Dead = true;
            Stats.Magic -= 8;
            SpellUsed = true;
        }
        if (SpellUsed == false)
        {
            cout << "You don\'t have enough magic!" << endl;
            PlayerMove(Stats, Position, Treasure, Monster, BattleContinue);
        }
        Monster.Health -= SpellDamage;
    }
}

void MonsterMove(StatsType &Stats, MonsterType &Monster)
{
     bool GotMove = false;
     do
     {
         int SpellDamage = 0;
         int RandNum = random(100) + 1;
         if (RandNum <= 45)
         {
             int Damage = Monster.Attack - (Stats.Defense * 0.5);
             if (Damage < 1)
             {
                 Damage = 1;
             }
             int HitProb = random(21) + 1;
             if (HitProb >= Stats.Dex)
             {
                 cout << "The monster attacked you and did " << Damage << " damage!" << endl;
                 Stats.Health -= Damage;
             }
             else
             {
                 cout << "The " << Monster.Name << " swung at you, but it missed!" << endl;
             }

             GotMove = true;
         }
         if ( (RandNum > 45 && RandNum <= 65) && (Monster.Magic >= 2) )
         {
             cout << "The " << Monster.Name << " called fire from heaven onto you!" << endl;
             SpellDamage = 10;
             cout << "It caused you " << SpellDamage << " damage!" << endl;
             Monster.Magic -= 2;
             GotMove = true;
         }
         if ( (RandNum > 65 && RandNum <= 85) && (Monster.Magic >= 2) )
         {
             cout << "The " << Monster.Name << " called down lightning from the sky";
             int HitProb = random(10);
             if (HitProb == 1)
             {
                 cout << ", but it missed!" << endl;
                 SpellDamage = 0;
             }
             else
             {
                 cout << "!" << endl;
                 SpellDamage = random(3) + 10;
                 cout << "It caused " << SpellDamage << " damage!" << endl;
             }
             Monster.Magic -= 2;
             GotMove = true;
         }
         if ( (RandNum > 85 && RandNum <= 90) && (Monster.Magic >= 3) )
         {
             cout << "The " << Monster.Name << " shot out a web and immobilized you!" << endl;
             Stats.Immobilize = 3;
             Monster.Magic -= 3;
             GotMove = true;
         }
         if ( (RandNum > 90 && RandNum <= 100) && (Monster.Magic >= 5) )
         {
             cout << "The monster cast the Heal spell on itself ";
             int HealAmount = random(3) + 4;
             cout << "and gained " << HealAmount << " health!" << endl;
             Monster.Health += HealAmount;
             Monster.Magic -= 5;
             GotMove = true;
         }
         Stats.Health -= SpellDamage;
     } while (GotMove == false);
}

void Battle(StatsType &Stats, PosType &Position, TreasureType Treasure)
{
    cout << endl;
    
    MonsterType Monster;

    PickMonster(Monster);

    bool BattleContinue = true;
    do
    {
        cout << endl;
        DispStats(Stats, Treasure);
        cout << "You are facing a " << Monster.Name << "!" << endl;

        if (Stats.Immobilize > 0)
        {
            cout << "You still can\'t move!" << endl;
            Stats.Immobilize--;
        }
        else
        {
            cout << endl;
            PlayerMove(Stats, Position, Treasure, Monster, BattleContinue);
        }

        if (Monster.Health <= 0)
        {
            Monster.Dead = true;
            BattleContinue = false;
        }

        if (BattleContinue == true)
        {
            if (Monster.Immobilize > 0)
            {
                cout << "The " << Monster.Name << " still can\'t move!" << endl;
            }
            else
            {
                MonsterMove(Stats, Monster);
            }
        }

        if (Stats.Health <= 0)
        {
            Stats.Dead = true;
            BattleContinue = false;
        }
    } while (BattleContinue == true);

    if (Monster.Dead == true)
    {
        cout << "You defeated the " << Monster.Name << "!" << endl;
        InsertBreak();
    }
    if (Stats.Dead == true)
    {
        cout << "The " << Monster.Name << " has defeated you!" << endl;
        InsertBreak();
    }
}

int _tmain(int argc, _TCHAR* argv[])
{
    randomize();
    Intro();

    StatsType Stats;
    char Race, Gender;
    GetStartStats(Stats, Race, Gender);

    Stats.WeaponName = "no weapon";
    Stats.ArmorName = "no armor";

    Stats.Gold = 50;
    StartEquip(Stats);

    PosType Position;
    Position.x = 0;
    Position.y = 0;
    Position.z = 0;

    FloorType Floor(8);

    StockCastle(Floor);
    // Display all floors
    /*for (int Counter = 0; Counter <= 7; Counter++)
    {
        for (int Counter1 = 0; Counter1 <= 7; Counter1++)
        {
            for (int Counter2 = 0; Counter2 <= 7; Counter2++)
            {
                cout << Floor[Counter].Space[Counter1][Counter2] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
    }*/

    bool End = false;
    bool Quit;
    
    TreasureType Treasure;
    Treasure.BlueFlame    = false;
    Treasure.GreenGem     = false;
    Treasure.NornStone    = false;
    Treasure.OminousGlobe = false;
    Treasure.OpalEye      = false;
    Treasure.Palantir     = false;
    Treasure.PalePearl    = false;
    Treasure.RubyRed      = false;
    Treasure.Silmaril     = false;

    do
    {
        DispStats(Stats, Treasure);
        DispFloor(Floor, Position);
        char Command = GetCommand(Stats);
        if (Command == 'H' || Command == 'h')
        {
            Help();
        }
        if (Command == 'N' || Command == 'n')
        {
            North(Position);
        }
        if (Command == 'S' || Command == 's')
        {
            South(Position);
        }
        if (Command == 'E' || Command == 'e')
        {
            East(Position);
        }
        if (Command == 'W' || Command == 'w')
        {
            West(Position);
        }
        if (Command == 'D' || Command == 'd')
        {
            if (Floor[Position.z].Space[Position.x][Position.y] == 'D')
            {
                Position.z--;
            }
            else
            {
                cout << endl;
                cout << "There are no stairs leading down from here!" << endl;
                cout << endl;
                InsertBreak();
            }
        }
        if (Command == 'U' || Command == 'u')
        {
            if (Floor[Position.z].Space[Position.x][Position.y] == 'U')
            {
                Position.z++;
            }
            else
            {
                cout << endl;
                cout << "There\'s no way up!" << endl;
                cout << endl;
                InsertBreak();
            }
        }
        if (Command == 'O' || Command == 'o')
        {
            char SpaceChar = Floor[Position.z].Space[Position.x][Position.y];
            if (SpaceChar == 'C')
            {
                OpenChest(Stats, Position, Floor);
            }
            else if (SpaceChar == 'B')
            {
                OpenBook(Stats, Position, Floor);
            }
            else
            {
                cout << endl;
                cout << "There is nothing to open!" << endl;
                cout << endl;
                InsertBreak();
            }
        }
        if (Command == 'G' || Command == 'g')
        {
            if (Floor[Position.z].Space[Position.x][Position.y] == 'O')
            {
                Gaze(Floor, Stats);
            }
        }
        if (Command == 'T' || Command == 't')
        {
            if (Stats.Runestaff == true)
            {
                Teleport(Position, Stats);
            }
            else
            {
                cout << endl;
                cout << "You can\t teleport without the Runestaff!" << endl;
                cout << endl;
                InsertBreak();
            }
        }
        if (Command == 'R' || Command == 'r')
        {
            if (Floor[Position.z].Space[Position.x][Position.y] == 'P')
            {
                Drink(Stats);
            }
        }
        if (Command == 'Q' || Command == 'q')
        {
            Quit = QuitGame(Stats);
            if (Quit == true)
            {
                End = true;
            }
        }
        if (Floor[Position.z].Space[Position.x][Position.y] == 'M')
        {
            Battle(Stats, Position, Treasure);
        }
        if (Stats.Dead == true)
        {
            Died(Stats, Position, Treasure);
            InsertBreak();
            End = true;
        }
    } while (End == false);

	return 0;
}
