#include "Clases.h"

void leeFichero(string name, int & num_v, int & num_ep, int & n_r_desc, int & num_c, int & num_cap_c, data_center & center, vector<Cache> & caches, vector<Endpoint> & endpoints);

int main() {
	int num_videos, num_endpoints, n_request_desc, num_caches, capacity_caches;
	data_center center;
	vector<Cache> caches;
	vector<Endpoint> endpoints;

	leeFichero("me_at_the_zoo.in", num_videos, num_endpoints, n_request_desc, num_caches, capacity_caches, center, caches, endpoints);
	//	for (int i = 0; i < (int)caches.size(); i++){
	//		caches[i].toString();
	//	}
	//	for (int i = 0; i < (int)endpoints.size(); i++){
	//		endpoints[i].toString();
	//	}

	ofstream myfile;
	myfile.open ("result.txt");
	myfile << "\n";
	myfile.close();
	return 0;
}

void leeFichero(string name, int & num_v, int & num_ep, int & n_r_desc, int & num_c, int & num_cap_c, data_center & center, vector<Cache> & caches, vector<Endpoint> & endpoints){
	string linea;
	ifstream infile;
	infile.open (name);
	string firstline="";

	getline(infile,firstline);

	stringstream ss;
	ss.str("");
	ss.clear();
	ss << firstline;

	ss >> num_v;
	ss >> num_ep;
	ss >> n_r_desc;
	ss >> num_c;
	ss >> num_cap_c;

	cout << "nº videos: " << num_v << ", nº endpoints: " << num_ep << endl;
	cout << "nº request descriptions: " << n_r_desc << " , nº caches: " << num_c << ", nº size: " << num_cap_c << endl;

	video_dc video0;
	vector<video_dc> videos;
	getline(infile,linea); // Saves the line in STRING.
	ss.clear();
	ss << linea;

	for (int i = 0; i < num_v; i++){ // To get you all the lines.
		video0.id = i;
		ss >> video0.size;
		videos.push_back(video0);
	}
	center.videos = videos;
	for (int i = 0; i < (int)videos.size(); i++){
		cout << "video " << videos[i].id << ": " << videos[i].size << endl;
	}


	for (int i = 0; i < num_ep; i++){
		Endpoint ep0;
		Cache c0;
		getline(infile,linea);
		ss.clear();
		ss << linea;
		int lat;
		ss >> lat;
		ep0.setLatenciaDataCenter(lat);
		int num_caches;
		ss >> num_caches;
		//		cout << "Num caches = " << num_caches << endl;
		for (int j = 0; j < num_caches; j++){
			getline(infile,linea); // Saves the line in STRING.
			ss.clear();
			ss << linea;
			cout << linea << endl;
			conexion_cache cc0;
			ss >> cc0.id;
			ss >> cc0.latencia_a_cache;
			vector<conexion_cache> cc = ep0.getCachesConectadas();
			cc.push_back(cc0);
			ep0.setCachesConectadas(cc);

			bool encontrado = false;
			for (int k = 0; k < (int)caches.size(); k++){
				if (caches[k].getId() == cc0.id){
					encontrado = true;
					continue;
				}
			}
			if (!encontrado){
				c0 = Cache(cc0.id, num_cap_c);
				caches.push_back(c0);
				c0.toString();
			}
		}
		ep0.toString();
		endpoints.push_back(ep0);
	}

	while (!infile.eof()){
		getline(infile,linea);
		ss.clear();
		ss << linea;
		video v0;
		ss >> v0.id ;
		int num_endpoint;
		ss >> num_endpoint;
		ss >> v0.requested;
		vector<video> vid = endpoints[num_endpoint].getVideosRequested();
		vid.push_back(v0);
		endpoints[num_endpoint].setVideosRequested(vid);
	}

	cout << "FINAL LIST " << endl << endl;
	for (int i = 0; i < (int)endpoints.size(); i++){
		endpoints[i].toString();
	}

}

void optimist_lattency ( vector<Endpoint> & endpoints, vector<Cache> &caches, data_center &center){
	for (int p = 0; p < endpoints.size(); p++){
		//Calculation of the brute lattency of each video
		int brute_lattency;
		int lattency = 0;
		for ( int i = 0; i < endpoints[p].videos_requested.size(); i++ )
		{

			lattency = endpoints[p].latencia_data_center * endpoints[p].videos_requested[i];
			brute_lattency += lattency;
		}
		//Determination of the maximum amount of requests a cache could satisfy depending on its memory

		int maximum_times, resto, deter_video;
		int menor = endpoints[p].videos_requested[0];
		deter_video = 0;
		for (int i = 1; i < endpoints[p].videos_requested.size(); i++)
		{
			if ( endpoints[p].videos_requested[i] < menor )
			{
				menor = endpoints[p].videos_requested[i];
				deter_video = i;
			}
		}
		maximum_times =  caches.capacidad_libre / menor;

		int maximum_memory_savable;
		maximum_memory_savable = brute_lattency - maximum_times*endpoints[p].videos_requested[deter_video];

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
