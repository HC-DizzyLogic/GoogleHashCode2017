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
void brute_lattency_force ( vector<Endpoint> & endpoints)
{
    //This function will provide the brute lattency of each video
    vector<int> brute_lattency;
    int lattency = 0;
        for ( int i = 0; i < endpoints.videos_requested.size(); i++ )
            {

                lattency = endpoints.latencia_data_center * videos_requested[i];
                brute_lattency.push_back(lattency);
            }
        /*for ( int i = 0; i < brute_lattency.size(); i++)
            {
                cout << brute_lattency[i] << endl;
            }
        */
}

void Node_Classificator ()
{
    //This function will order the endpoints depending on their brute lattency
}
