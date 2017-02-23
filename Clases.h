#include "Hash.h"

class Cache{
public:

	Cache (void){
		this->id = 0;
		this->capacidad_libre = 0;
		vector<video> v_a;
		this->videos_almacenados = v_a;
	}

	Cache (int id, int c_l){
		this->id = id;
		this->capacidad_libre = c_l;
		vector<video> v_a;
		this->videos_almacenados = v_a;
	}

	Cache (int id, int c_l, vector<video> v_a){
		this->id = id;
		this->capacidad_libre = c_l;
		this->videos_almacenados = v_a;
	}

	int getCapacidadLibre() const {
		return capacidad_libre;
	}

	void setCapacidadLibre(int capacidadLibre) {
		capacidad_libre = capacidadLibre;
	}

	const vector<video>& getVideosAlmacenados() const {
		return videos_almacenados;
	}

	void setVideosAlmacenados(const vector<video>& videosAlmacenados) {
		videos_almacenados = videosAlmacenados;
	}

	int getId() const {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	void toString(){
		cout << "Cache " << id << ": CL = " << capacidad_libre << ", VA = " << (int)videos_almacenados.size() << endl;
	}

private:
	int id;
	int capacidad_libre;
	vector<video> videos_almacenados;
};

class Endpoint{
public:

	Endpoint(void){
		vector<video> v;
		this->videos_requested = v;
		this->latencia_data_center = 0;
		vector<conexion_cache> cc;
		this->caches_conectadas = cc;
	}

	Endpoint(vector<video> & v_r, int l_d_c, vector<conexion_cache> c_c){
		this->videos_requested = v_r;
		this->latencia_data_center = l_d_c;
		this->caches_conectadas = c_c;
	}

	const vector<conexion_cache>& getCachesConectadas() const {
		return caches_conectadas;
	}

	void setCachesConectadas(const vector<conexion_cache>& cachesConectadas) {
		caches_conectadas = cachesConectadas;
	}

	int getLatenciaDataCenter() const {
		return latencia_data_center;
	}

	void setLatenciaDataCenter(int latenciaDataCenter) {
		latencia_data_center = latenciaDataCenter;
	}

	const vector<video>& getVideosRequested() const {
		return videos_requested;
	}

	void setVideosRequested(const vector<video>& videosRequested) {
		videos_requested = videosRequested;
	}

	void toString(){
		cout << "Endpoint. VR: " ;
		for (int i = 0; i < (int)videos_requested.size(); i++){
			cout << videos_requested[i].id << " " << videos_requested[i].requested << endl;
		}
		cout << " latencia : " << latencia_data_center << endl;
		cout << "Caches conectadas : " << endl;
		for (int i = 0; i < (int)caches_conectadas.size(); i++){
			cout << caches_conectadas[i].id << " " << caches_conectadas[i].latencia_a_cache << endl;
		}
	}

private:
	vector<video> videos_requested;
	int latencia_data_center;
	vector<conexion_cache> caches_conectadas;
};

