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

void leeFichero(string name, data_center & center, vector<Cache> & caches, vector<Endpoint> & endpoints)
{
      }
 void brute_lattency_force ()
{
    //This function will provide the brute lattency of each video
    vector<int> nodo = {1,2,3};
    int no_times = 1500;
    vector<int> brute_lattency;
    int lattency = 0;
    int delay_datacenter = 1000;
    int no_requests = 3;
        for ( int i = 0; i < nodo.size(); i++ )
            {
                cout << "huehue" << endl;
                lattency = delay_datacenter * no_requests;
                brute_lattency.push_back(lattency);
            }
        for ( int i = 0; i < brute_lattency.size(); i++)
            {
                cout << brute_lattency[i] << endl;
            }
}
