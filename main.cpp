#include <bits/stdc++.h>

using namespace std;
struct sheep
{
    string name;
    string dna;
    int k;
};
int getRate(string chosen, string simple, int lentgh);
void sortSheeps(sheep *avis, int rows);
void read(ifstream &in, sheep * avis, int rows);
void write(ofstream &out, sheep * avis, int rows);


int main()
{
    ifstream in("U2.txt");
    ofstream out("U2rez.txt");


    //kintamieji
    int rows;
    int length;
    int index;
    in>>rows>>length>>index;
    //index 1 mazesnis, nes nuo nulio skaiciuojam
    index-=1;
    sheep avis[rows];
    //1 reikalavimas. Skaitymo funkcija
    read(in, avis, rows);

    //2 reikalavimas. Koeficiento funkcija
    for(int i=0; i<rows; i++)
    {
        //index representuoja isrinkta avi
        avis[i].k = getRate(avis[index].dna, avis[i].dna, length);
    }

    //3 reikalavimas. Rikiavimo funkcija
    sortSheeps(avis, rows);
    //4 reikalavimas. Rasymo funkcija
    write(out, avis, rows);

    in.close();
    out.close();
    return 0;
}
int getRate(string chosen, string simple, int lentgh)
{
    //patikrina visu (ir index avies) koeficienta
    int k = 0;
    for(int i=0; i<lentgh; i++)
    {
        if(chosen.at(i)==simple.at(i))
        {
            k++;
        }
    }
    return k;
}

void sortSheeps(sheep *avis, int rows)
{
    //rikiuoja avis, index avis bus virsuje, nes dnr negali buti vienodos
    for(int i=0; i<rows-1; i++)
    {
        for(int j=i+1; j<rows; j++)
        {
            if(avis[i].k<avis[j].k)
            {
                swap(avis[i], avis[j]);
            }
            else if(avis[i].k == avis[j].k)
            {
                if(avis[i].name > avis[j].name)
                {
                    swap(avis[i], avis[j]);
                }
            }
        }
    }
}
void read(ifstream &in, sheep * avis, int rows)
{
    string tempName;
    //Sukuriu 11 char ilgio string
    tempName.resize(11);

    //c++ skaitymas nereaguoja į '\n' char ir ji palieka
    //todel isvalau perskaitydamas 1 char
    in.read( &tempName[0], 1);
    for(int i=0; i<rows; i++)
    {
        in.read( &tempName[0], 11);
        avis[i].name = tempName;
        in>>avis[i].dna;
        in.read( &tempName[0], 1);
    }
}
void write(ofstream &out, sheep * avis, int rows)
{
    //0 avis visada yra index avis
	out<<avis[0].name<<endl;
	for(int i=1; i<rows; i++){
		out<<avis[i].name<<avis[i].k<<endl;
	}
}
