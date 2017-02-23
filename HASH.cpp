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
