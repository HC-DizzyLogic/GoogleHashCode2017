#include "Endpoint.h"

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

void leeFichero(string name, data_center & center, vector<Cache> & caches, vector<Endpoint> & endpoints){
		string linea;
		ifstream infile;
		infile.open (name);
		string firstline="";

		getline(infile,firstline);

		stringstream ss;
		ss.str("");
		ss.clear();
		ss << firstline;

		ss >> rows;
		ss >> cols;
		ss >> min;
		ss >> max;

		cout << "nº de filas: " << rows << ", nº de columnas: " << cols << endl;
		cout << "nº de ingredientes de cada tipo: " << min << " , nº max de casillas: " << max << endl;

		pizza = vector<vector<char> > (rows, vector<char> (cols, 0));

		for (int i = 0; i < rows; i++){ // To get you all the lines.
			getline(infile,linea); // Saves the line in STRING.
			for (int j = 0; j < cols; j++){
				pizza[i][j] = linea.at(j);
				cout << pizza[i][j];
			}
			cout<< endl;
		}
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
