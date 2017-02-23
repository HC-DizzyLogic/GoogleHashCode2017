#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct data_center {
	vector<int> video_id;
	vector<int> video_size;
};

struct video {
	int id;
	int requested;
};

struct conexion_cache {
	int id;
	int latencia_a_cache;
};
