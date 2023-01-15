#include <iostream>
#include <sstream>


using namespace std;

class Stad{

string namn;
int temp;

public:

void SetNT(string x, int y){
namn = x;
temp = y;
}

string ToString(){
    stringstream ss;
    ss << namn << ", " << temp;

    string returnString = ss.str();

    return returnString;
}
};

int LinSok(int stader[],int n,int sokTemp){

   for(int i = 0; i < n; i++)
   {
       if(stader[i] == sokTemp)
       {
           return i;
       }

   }
   return -1;
}

void BubbleSort(int stader[],string sNamn[],int n){

    for(int i = 0; i < n; i++)
    {
        int nrLeft = n - i;

        for(int j = 0; j < nrLeft; j++)
        {
            if(stader[j] > stader[j+1])
            {
                int bytTemp = stader[j];
                string stadByt = sNamn[j];
                stader[j] = stader[j+1];
                sNamn[j] = sNamn[j+1];
                stader[j+1] = bytTemp;
                sNamn[j+1] = stadByt;



            }
        }
    }


}

int main()
{
int sokTemp;
Stad stad[4];
string stadNamn[4];
int temper[4];

cout << "Detta program sorterar och soker stader efter temperatur.\n\n";

do
{
    cout << "Ange en temperatur som programmet ska soka efter (-60 till 60): ";
    cin >> sokTemp;
} while(sokTemp <= -60 && sokTemp >= 60);

for(int i = 0; i < 4; i++){

string angNamn;
int angTemp;

cout << "\nAnge namnet pa stad nummer " << i+1 << ": ";
cin >> angNamn;

do
{
    cout << "Ange temperaturen i " << angNamn << "(-60 till 60): ";
    cin >> angTemp;
} while(angTemp <= -60 && angTemp >= 60);

stad[i].SetNT(angNamn, angTemp);
stadNamn[i] = angNamn;
temper[i] = angTemp;
}

BubbleSort(temper,stadNamn, 4);

for(int i = 0; i < 4; i++)
{
    stad[i].SetNT(stadNamn[i], temper[i]);
}

cout << endl << "Staderna sorterade efter temperatur (lagst forst): \n";
for(int i = 0; i < 4; i++)
{
    cout << stad[i].ToString() << endl;
}

int result = LinSok(temper, 4, sokTemp);

if(result >= 0)
{
    cout << "\nDu sokte en stad som ar " << sokTemp << " grader. Programmet hittade: " << stad[result].ToString() << " grader pa index position " << result << endl;
}
else
{
    cout << "\nDu sokte en stad som ar " << sokTemp << " grader. Programmet hittade inte en stad som stammer in pa din sokning.\n";
}

return 0;
}

/*
PSEUDOKOD LINSOK

Ta in array , antal loopar och söktemperatur.

repetera antal loopar gånger

Om array index 0 plus 1 per loop genomförd är lika med söktemperatur
returnera 0 plus 1 per loop genomförd

annars returnera -1
*/

/* Jag har börjat med att göra klassen stad. Sedan skapade jag funktionen ToString som kombinerar stadens namn och temperatur till en utskrift.
Efter det skapade jag funktionen LinSok som gör en linjär sökning av ett tal som användaren väljer. efter det skapade jag bubblesort som sorterar städer
efter temperatur.

Jag börjar sen med mainfunktionen. Jag följer ordningen som står i uppgiften och skapar variabler och arrayer. Jag informerar användaren om vad programmet
gör. Efter det så tar jag in relevant information från användaren och kontrollerar att graderna användaren har angivit är rimliga. Jag anropar sedan
funktionen bubblesort för att sortera städerna efter temperatur. Och matar sedan ut städerna i ordning med hjälp av ToString. Jag anropar funktionen
LinSok för att se om temperaturen användaren angav i början av programmet. Om temperaturen stämmer in på någon av städerna så kommer ett medelande ut om
att programmet hittade staden och programmet anger också indexpositionen på staden. Om temperaturen inte stämmer in på någon stad så informeras användaren
om att det inte kunde hitta någon relevant stad.

Programmet avslutas.
*/
