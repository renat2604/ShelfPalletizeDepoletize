#include <iostream>
#include <fstream>

using namespace std;

#define DEBUG

struct shelf;
struct channel;
struct pointBox;
struct palletBox;

void convertChar_shortInt(char* str, short int& result, unsigned __int8& i)
{
    result = result xor result;
    while (str[i] != ',')
    {
        result *= 10;
        result += str[i] - 48;
        i++;
    }
    i++;
}


struct stackShelf
{
    shelf* shelfRef[15];
    __int8 posShelf = 0;
};

struct shelf
{
    channel* channelRef[10];
    __int8 posChannel = 0;
};

struct pointsBox
{
    char SKU[4];
    short int x1;
    short int y1;
    short int z1;
    short int x2;
    short int y2;
    short int z2;
};

struct palletBox
{
    char SKU[4];
    short int quantity{};
    short int lenght{};
    short int width{};
    short int height{};
    short int weight{};
    short int strenght{};
    short int aisle{};
    short int caustic{};
};

struct progBox
{
    char SKU[4];
};

struct channel
{
    progBox mass[8];
    __int8 posMass = 0;
};

struct countBoxOfType
{
    unsigned __int8 countBox{};
    char SKU[4];
};

struct palletInfo
{
    char* palletId;
    palletBox* mass;
    unsigned __int16 countType;
};

void boxFiller(char* str, palletInfo& info, unsigned __int16& numberMass)
{
    unsigned __int8 i = 0, j = 0;
    for (; i < 4; i++)
    {
        info.mass[numberMass].SKU[i] = str[i];
    }
    i += 2;
    for (; i < 48; i++)
    {
        switch (j)
        {
        case 0:
        {
            convertChar_shortInt(str, info.mass[numberMass].quantity, i);
            goto ___J;
        }
        case 1:
        {
            convertChar_shortInt(str, info.mass[numberMass].lenght, i);
            goto ___J;
        }
        case 2:
        {
            convertChar_shortInt(str, info.mass[numberMass].width, i);
            goto ___J;
        }
        case 3:
        {
            convertChar_shortInt(str, info.mass[numberMass].height, i);
            goto ___J;
        }
        case 4:
        {
            convertChar_shortInt(str, info.mass[numberMass].weight, i);
            goto ___J;
        }
        case 5:
        {
            convertChar_shortInt(str, info.mass[numberMass].strenght, i);
            goto ___J;
        }
        case 6:
        {
            convertChar_shortInt(str, info.mass[numberMass].aisle, i);
            goto ___J;
        }
        case 7:
        {
            convertChar_shortInt(str, info.mass[numberMass].caustic, i);
            goto ___J;
        }
        }
    ___J:;
        j++;
        if (j == 8)
        {
            return;
        }
    }
}

void requestListType(countBoxOfType* boxType, char* str, unsigned short int& countBoxType)
{
    unsigned __int8 i = 0, j = 0;
    if (str[i] != '\0')
    {
        do
        {
            while (boxType[j].SKU[i] == str[i])
            {
                i++;
                if (i == 4)
                {
                    return;
                }
            }
            i = 0;
        } while (j++ < countBoxType);
        while (str[i] != ',')
        {
            boxType[countBoxType].SKU[i] = str[i];
            i++;
        }
        countBoxType++;
    }
}

void blockDepaletize(countBoxOfType* &countBox, unsigned __int16 typeStart, unsigned __int16 typeEnd)
{
    while (typeStart < typeEnd)
    {
        if (countBox[typeStart].countBox < 15)
        {
            countBox[typeStart].countBox += 50;
        }
        typeStart++;
    }
}

void shelfFiller(stackShelf*& block, countBoxOfType*& boxType, unsigned short int& boxTypeNum, unsigned __int8& i, unsigned __int32& time, fstream& depalletize)
{
    unsigned __int8 j1 = 7, h = 0, k = 0, j = 0, endMass = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass, endChannel = block->shelfRef[block->posShelf]->posChannel, endShelf = block->posShelf;
    countBoxOfType* t;
    unsigned __int32 save{};
    char ex[84] = "|        |       |           |         |           |                              |";
    do
    {
        do
        {
            do
            {
                if (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass].SKU[0] == '`')
                {
                    t = &boxType[i % boxTypeNum];
                    time++;
                    save = time;
                    while (save > 0)
                    {
                        ex[j1] = (save % 10) + 48;
                        save /= 10;
                        j1--;
                    }
                    j1 = 15;
                    save = (unsigned __int32)(i % boxTypeNum);
                    do
                    {
                        ex[j1] = (save % 10) + 48;
                        save /= 10;
                        j1--;
                    } while (save > 0);
                    ex[27] = '1';
                    j1 = 37;
                    ex[36] = ' ';
                    save = block->posShelf;
                    do
                    {
                        ex[j1--] = (save % 10) + 48;
                        save /= 10;
                    } while (save > 0);
                    ex[49] = block->shelfRef[block->posShelf]->posChannel + 48;
                    ex[80] = '~';
                    //"|  time  | boxID | eventtype | stackID | channelID |           palletID           |";
                    for (h = 0; h < 84; h++)
                    {
                        depalletize << ex[h];
                    }
                    depalletize << endl;
                    i++;
                    j1 = 7;
                    j++;
                    if (j == 7)
                    {
                        j = 0;
                        i--;
                    }
                    for (__int8 k = 0; k < 4; k++)
                    {
                        block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass].SKU[k] = t->SKU[k];
                    }
                    t->countBox--;
                }
                block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass++;
                if (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass == 8)
                {
                    block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass -= 8;
                }
            } while (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass != endMass);
            block->shelfRef[block->posShelf]->posChannel++;
            if (block->shelfRef[block->posShelf]->posChannel == 10)
            {
                block->shelfRef[block->posShelf]->posChannel -= 10;
            }
        } while (block->shelfRef[block->posShelf]->posChannel != endChannel);
        block->posShelf++;
        if (block->posShelf == 15)
        {
            block->posShelf -= 15;
        }
    } while (block->posShelf != endShelf);
    cout << time << endl;
}

void palletFiller(palletBox*& type /*передавать через palletInfo*/, stackShelf*& block, unsigned __int16& boxTypeNumberEnd, unsigned __int32& time, fstream& palletize, char* palletId)
{
    unsigned __int8 h = 0, boxTypeNumber = 0, k = 0, offset = 0, endShelf = block->posShelf, endChannel = block->shelfRef[block->posShelf]->posChannel, endMass = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass;
    unsigned __int32 save;
    char ex[84] = "|        |       |           |         |           |                              |";
    while (boxTypeNumber < boxTypeNumberEnd)
    {
        do
        {
            do
            {
                for (k = 3; k != 255; k--)
                {
                    if (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[(block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass + offset) % 8].SKU[k] != type[boxTypeNumber].SKU[k])
                    {
                        block->shelfRef[block->posShelf]->posChannel++;
                        if (block->shelfRef[block->posShelf]->posChannel == 10)
                        {
                            block->shelfRef[block->posShelf]->posChannel -= 10;
                        }
                        endMass = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass;
                        goto ___if_1;
                    }
                }
                if (offset)
                {
                    __int8 chToCh = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass;
                    do
                    {
                        chToCh--;
                        if (chToCh == -1)
                        {
                            chToCh += 8;
                        }
                        if (chToCh == block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass)
                        {
                            while (!chToCh)
                            {
                                time += 2;
                                save = time;
                                k = 7;
                                do
                                {
                                    ex[k] = (save % 10) + 48;
                                    save /= 10;
                                    k--;
                                } while (save > 0);
                                k = 15;
                                save = boxTypeNumber;
                                do
                                {
                                    ex[k] = (save % 10) + 48;
                                    save /= 10;
                                    k--;
                                } while (save > 0); 
                                ex[27] = '3';
                                k = 37;
                                ex[36] = ' ';
                                save = block->posShelf;
                                do
                                {
                                    ex[k--] = (save % 10) + 48;
                                    save /= 10;
                                } while (save > 0);
                                ex[49] = block->shelfRef[block->posShelf]->posChannel + 48;
                                k = 80;
                                h = 0;
                                while (palletId[h])
                                {
                                    h++;
                                }
                                do
                                {
                                    ex[k] = palletId[h];
                                    h--;
                                    k--;
                                } while (h);
                                for (h = 0; h < 84; h++)
                                {
                                    palletize << ex[h];
                                }
                                palletize << endl;
                                //"|  time  | boxID | eventtype | stackID | channelID |           palletID           |";
                                chToCh--;
                            }
                            block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass = (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass + offset) % 8;
                            offset = 0;
                            goto ___ChToCh_1;
                        }
                    } while (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[chToCh].SKU[0] == '`');
                    chToCh++;
                    if (chToCh == 8)
                    {
                        chToCh -= 8;
                    }
                    while (offset)
                    {
                        for (k = 0; k < 4; k++)
                        {
                            block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[chToCh].SKU[k] = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass].SKU[k];
                        }
                        time += 2;
                        save = time;
                        k = 7;
                        do
                        {
                            ex[k] = (save % 10) + 48;
                            save /= 10;
                            k--;
                        } while (save > 0);
                        k = 15;
                        save = boxTypeNumber;
                        do
                        {
                            ex[k] = (save % 10) + 48;
                            save /= 10;
                            k--;
                        } while (save > 0);
                        ex[27] = '3';
                        k = 37;
                        ex[36] = ' ';
                        save = block->posShelf;
                        do
                        {
                            ex[k--] = (save % 10) + 48;
                            save /= 10;
                        } while (save > 0);
                        ex[49] = block->shelfRef[block->posShelf]->posChannel + 48;
                        k = 80;
                        h = 0;
                        while (palletId[h])
                        {
                            h++;
                        }
                        do
                        {
                            ex[k] = palletId[h];
                            h--;
                            k--;
                        } while (h);
                        for (h = 0; h < 84; h++)
                        {
                            palletize << ex[h];
                        }
                        palletize << endl;
                        block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass++;
                        if (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass == 8)
                        {
                            block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass -= 8;
                        }
                        offset--;
                        chToCh++;
                        if (chToCh == 8)
                        {
                            chToCh -= 8;
                        }
                    }
                ___ChToCh_1:;
                }
                block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->mass[block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass].SKU[0] = '`';
                type[boxTypeNumber].quantity--;
                time++;
                save = time;
                k = 7;
                do
                {
                    ex[k] = (save % 10) + 48;
                    save /= 10;
                    k--;
                } while (save > 0);
                k = 15;
                save = boxTypeNumber;
                do
                {
                    ex[k] = (save % 10) + 48;
                    save /= 10;
                    k--;
                } while (save > 0); 
                ex[27] = '2';
                k = 37;
                ex[36] = ' ';
                save = block->posShelf;
                do
                {
                    ex[k--] = (save % 10) + 48;
                    save /= 10;
                } while (save > 0);
                ex[49] = block->shelfRef[block->posShelf]->posChannel + 48;
                k = 80;
                h = 0;
                while (palletId[h])
                {
                    h++;
                }
                do
                {
                    ex[k] = palletId[h];
                    h--;
                    k--;
                } while (h);
                for (h = 0; h < 84; h++)
                {
                    palletize << ex[h];
                }
                palletize << endl;
                block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass++;
                if (block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass == 8)
                {
                    block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass -= 8;
                }
                endMass = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass;
                if (type[boxTypeNumber].quantity == 0)
                {
                    boxTypeNumber++;
                    endShelf = block->posShelf;
                    endChannel = block->shelfRef[block->posShelf]->posChannel;
                    goto ___end_1;
                }
            ___if_1:;
            } while (block->shelfRef[block->posShelf]->posChannel != endChannel);
            block->posShelf++;
            if (block->posShelf == 15)
            {
                block->posShelf -= 15;
            }
            endChannel = block->shelfRef[block->posShelf]->posChannel;
            endMass = block->shelfRef[block->posShelf]->channelRef[block->shelfRef[block->posShelf]->posChannel]->posMass;
        } while (block->posShelf != endShelf);
        offset++;
    ___end_1:;
    }
    cout << time << endl;
}

void allocCountBoxOfType(countBoxOfType* &old, unsigned __int16& size)
{
    char* SKU = (char*)malloc(sizeof(char) * size * 4);
    __int8* countBox = (__int8*)malloc(sizeof(__int8) * size);
    for (unsigned __int16 i = 0; i < size; i++)
    {
        countBox[i] = old[i].countBox;
        for (__int8 j = 0; j < 4; j++)
        {
            SKU[i * 4 + j] = old[i].SKU[j];
        }
    }
    free(old);
    old = nullptr;
    size += 5;
    while (old == nullptr)
    {
        old = (countBoxOfType*)realloc(old, sizeof(countBoxOfType) * size);
    }
    unsigned __int16 i = 0;
    for (; i < size - 5; i++)
    {
        old[i].countBox = countBox[i];
        for (__int8 j = 0; j < 4; j++)
        {
            old[i].SKU[j] = SKU[i * 4 + j];
        }
    }
    for (; i < size; i++)
    {
        old[i].countBox = 0;
    }
    free(SKU);
    free(countBox);
}

void allocPalletInfo(palletInfo* &old, unsigned __int16& size)
{
    char** palletId = nullptr;
    palletBox** mass = nullptr;
    unsigned __int16* countBox = nullptr;
    while (palletId == nullptr)
    {
        palletId = (char**)malloc(sizeof(char*) * size);
    }
    while (mass == nullptr)
    {
        mass = (palletBox**)malloc(sizeof(palletBox*) * size);
    }
    while (countBox == nullptr)
    {
        countBox = (unsigned __int16*)malloc(sizeof(unsigned __int16) * size);
    }
    for (unsigned __int16 i = 0; i < size; i++)
    {
        palletId[i] = old[i].palletId;
        old[i].palletId = nullptr;
        mass[i] = old[i].mass;
        old[i].mass = nullptr;
        countBox[i] = old[i].countType;
    }
    size += 5;
    free(old);
    old = nullptr;
    while (old == nullptr)
    {
        old = (palletInfo*)realloc(old, sizeof(palletInfo) * size);
    }
    for (unsigned __int16 i = 0; i < size - 5; i++)
    {
        old[i].palletId = palletId[i];
        palletId[i] = nullptr;
        old[i].mass = mass[i];
        mass[i] = nullptr;
        old[i].countType = countBox[i];
    }
    for (unsigned __int8 i = size - 5; i < size; i++)
    {
        old[i].mass = (palletBox*)malloc(sizeof(palletBox) * 50);
    }
    free(countBox);
    free(mass);
    free(palletId);
}

void palletLoggerStart(fstream& palletLog, __int16& i, unsigned __int32 save)
{
    char ex[47] = "|      |          |              |           |";
    unsigned __int8 j1 = 5;
    while (save > 0)
    {
        ex[j1--] = (save % 10) + 48;
        save /= 10;
    }
    j1 = 16;
    save = (unsigned __int32)i;
    do
    {
        ex[j1--] = (save % 10) + 48;
        save /= 10;
    } while (save > 0);
    j1 = 31;
    save = (unsigned __int32)i;
    do
    {
        ex[j1--] = (save % 10) + 48;
        save /= 10;
    } while (save > 0);
    ex[43] = '4';
    for ( unsigned __int8 h = 0; h < 47; h++)
    {
        palletLog << ex[h];
    }
    palletLog << endl;
}

void palletLoggerEnd(fstream& palletLog, __int16& i, unsigned __int32 save)
{
    char ex[47] = "|      |          |              |           |";
    unsigned __int8 j1 = 5;
    while (save > 0)
    {
        ex[j1--] = (save % 10) + 48;
        save /= 10;
    }
    j1 = 16;
    save = (unsigned __int32)i;
    do
    {
        ex[j1--] = (save % 10) + 48;
        save /= 10;
    } while (save > 0);
    j1 = 31;
    save = (unsigned __int32)i;
    do
    {
        ex[j1--] = (save % 10) + 48;
        save /= 10;
    } while (save > 0);
    ex[43] = '7';
    for (unsigned __int8 h = 0; h < 47; h++)
    {
        palletLog << ex[h];
    }
    palletLog << endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    unsigned __int16 countBoxType = 0, numberBox = 0;
    unsigned __int16 countBoxOfTypeSize = 5, palletInfoSize = 5;
    unsigned __int8 countBoxTypeForPallet = 0, numberPalletProg = 0, palletIdSize = 15;
    unsigned __int8 shelfFillerI = 0;
    unsigned __int32 time = 0;
    __int8 numeral[13], numeralI = 0, numberPalletFile = 2, numberSave = numberPalletFile;
    char str[48], path[64] = "PathWithFileName", pathEnd[5] = ".csv";
    fstream pallet, depalletize, palletize, palletLog;
    countBoxOfType* countPalletBox = (countBoxOfType*)malloc(sizeof(countBoxOfType) * countBoxOfTypeSize);
    for (unsigned __int8 i = 0; i < countBoxOfTypeSize; i++)
    {
        countPalletBox[i].countBox = 0;
    }
    palletInfo* info = nullptr;
    while (info == nullptr)
    {
        info = (palletInfo*)malloc(sizeof(palletInfo) * palletInfoSize);
    }
    for (__int8 i = 0; i < palletInfoSize; i++)
    {
        info[i].mass = (palletBox*)malloc(sizeof(palletBox) * 50);
        if (!info[i].mass)
        {
            free(info[i].mass);
            i--;
        }
    }
    stackShelf* block = (stackShelf*)malloc(sizeof(stackShelf));
    block->posShelf = 0;
    shelf* s;
    channel* c;
    for (__int8 i = 0; i < 15; i++)
    {
        s = (shelf*)malloc(sizeof(shelf));
        s->posChannel = 0;
        block->shelfRef[i] = s;
        for (__int8 j = 0; j < 10; j++)
        {
            c = (channel*)malloc(sizeof(channel));
            c->posMass = 0;
            block->shelfRef[i]->channelRef[j] = c;
            for (__int8 k = 0; k < 8; k++)
            {
                block->shelfRef[i]->channelRef[j]->mass[k].SKU[0] = '`';
            }
        }
    }
    s = nullptr;
    c = nullptr;
    palletLog.open("palletLog.csv", ios::trunc | ios::in | ios::out);
    if (!palletLog.is_open())
    {
        cout << "Ошибка.";
    }
    else
    {
        cout << "Файл лога паллет открыт." << endl;
        //palletLog << "startDepalletize" << endl;
        palletLog << "| time | palletID | palletTypeID | eventtype |" << endl << "|      |          |              |           |" << endl;
    }
    depalletize.open("depalletize.csv", ios::trunc | ios::in | ios::out);
    if (!depalletize.is_open())
    {
        cout << "Ошибка.";
    }
    else
    {
        cout << "Файл депаллетизации открыт." << endl;
        depalletize << "startDepalletize" << endl;
        depalletize << "|  time  | boxID | eventtype | stackID | channelID |           palletID           |" << endl << "|        |       |           |         |           |                              |" << endl;
    }
    palletize.open("palletize.csv", ios::trunc | ios::in | ios::out);
    if (!palletize.is_open())
    {
        cout << "Ошибка.";
    }
    else
    {
        cout << "Файл паллетизации открыт." << endl;
        palletize << "startPalletize" << endl;
        palletize << "|  time  | boxID | eventtype | stackID | channelID |           palletID           |" << endl << "|        |       |           |         |           |                              |" << endl;
    }
    do
    {
        do
        {
            numeral[numeralI] = numberPalletFile % 10;
            numberPalletFile /= 10;
            numeralI++;
        } while (numberPalletFile > 0);
        numberPalletFile = ++numberSave;
        numberSave = --numeralI;
        for (__int16 i = /*OffsetToTheNumber "Order_" file*/; numeralI >= 0; numeralI--, i++)
        {
            path[i] = numeral[numeralI] + 48;
        }
        for (__int16 i = /*OffsetToTheNumber "Order_" file*/ + 1 + numberSave; i < /*OffsetToTheNumber "Order_" file*/ + 4 + numberSave; i++)
        {
            path[i] = pathEnd[i - /*OffsetToTheNumber "Order_" file*/ + 1 - numberSave];
        }
        numberSave = numberPalletFile;
        numeralI = 0;
        pallet.open(path);
        if (!pallet.is_open())
        {
            cout << "Конец файлов." << endl;
            goto ___endRequestFilling_1;
        }
        else
        {
            cout << "Файл паллеты открыт." << endl;
            pallet.getline(str, 48);
            {
                palletIdSize = 0;
                while (str[palletIdSize] != '\000')
                {
                    palletIdSize++;
                }
                info[numberPalletProg].palletId = (char*)malloc(sizeof(char) * (palletIdSize + (unsigned __int8)1));
            }
            for (__int8 i = 0; i < palletIdSize; i++)
            {
                info[numberPalletProg].palletId[i] = str[i];
            }
            info[numberPalletProg].palletId[palletIdSize] = '\000';
            while (pallet.get() != '\n');
            do
            {
                pallet.getline(str, 48);
                if (str[0] == '\0')
                {
                    goto ___endCVSRead_1;
                }
                boxFiller(str, info[numberPalletProg], numberBox); // paletize
                requestListType(countPalletBox, str, countBoxType); // depaletize
                numberBox++;
                if (countBoxType == countBoxOfTypeSize)
                {
                    allocCountBoxOfType(countPalletBox, countBoxOfTypeSize);
                }
            } while (!pallet.eof());
        ___endCVSRead_1:;
            info[numberPalletProg].countType = numberBox;
            if (numberPalletProg + 1 == palletInfoSize)
            {
                allocPalletInfo(info, palletInfoSize);
            }
            numberPalletProg++;
            numberBox = 0;
            pallet.close();
        }
    } while (true);
___endRequestFilling_1:;
    __int16 i = 0;
    while (i < numberPalletProg)
    {
        blockDepaletize(countPalletBox, 0, countBoxType); // depaletize
        shelfFiller(block, countPalletBox, countBoxType, shelfFillerI, time, depalletize); // depaletize
        palletLoggerStart(palletLog, i, time);
        palletFiller(info[i].mass, block, info[i].countType, time, palletize, info[i].palletId); // paletize
        palletLoggerEnd(palletLog, i, time);
        i++;
    }
    blockDepaletize(countPalletBox, 0, countBoxType); // depaletize
    shelfFiller(block, countPalletBox, countBoxType, shelfFillerI, time, depalletize); // depaletize
    depalletize << "finishDepalletize" << endl;
    depalletize.close();
    cout << "Файл депаллетизации закрыт." << endl;
    palletize << "finishPalletize" << endl;
    cout << "Файл паллетизации закрыт." << endl;
    palletize.close();
    //palletLog << "finishPalletize" << endl;
    cout << "Файл лога паллет закрыт." << endl;
    palletLog.close();
    cout << time;
    cout << endl;
}
