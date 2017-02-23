#include "hash.h"
#include "cache.h"
#include "endpoint.h"


using namespace std;

int main() {
    data_center center;
    vector<Cache> caches;
    vector<Endpoint> endpoints;


    ofstream myfile;
    myfile.open ("result.txt");
    myfile << "\n";
    myfile.close();

    return 0;
}

void leeFichero (string name, data_center & center, vector<Cache> & caches, vector<Endpoint> & endpoints)
{

}
void optimist_lattency ( vector<Endpoint> & endpoints, vector<Cache> &caches, data_center &center)
{
    //Calculation of the brute lattency of each video
    int brute_lattency;
    int lattency = 0;
        for ( int i = 0; i < endpoints.videos_requested.size(); i++ )
            {

                lattency = endpoints.latencia_data_center * videos_requested[i];
                brute_lattency += lattency;
            }
     //Determination of the maximum amount of requests a cache could satisfy depending on its memory

     int maximum_times, resto, deter_video;
     int menor = endpoints.videos_requested[0];
     deter_video = 0;
        for (int i = 1; i < endpoints.videos_requested.size(); i++)
        {
            if ( endpoints.videos_requested[i] < menor )
            {
                menor = endpoints.videos_requested[i];
                deter_video = i;
            }
        }
        maximum_times =  caches.capacidad_libre / menor;

     int maximum_memory_savable;
     maximum_memory_savable = brute_lattency - maximum_times*endpoints.videos_requested[deter_video];

    }
}

void Node_Classificator (vector<Endpoint> & endpoints)
{
    //This function will order the endpoints depending on their brute lattency
    vector <int> nodes_priorized ;
    int pos = 0;
    int min = maximum_times[0]; //ordenarlo bien, definirlo con respecto a una estructura
    for ( int j = 0; j < numero_de_nodos_definir; j ++)
    {

        for ( int i = 0; i < numero_de_nodos_definir; i++)
            {
                if ( maximum_times[i] < min )
                {
                    min = maximum_times[i];
                    pos = i;
                }
            }
      min = maximum_times[pos];
      nodes_priorized.push_back(pos);
    }
}
