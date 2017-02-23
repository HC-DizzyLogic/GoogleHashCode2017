#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct video_dc {
	int id;
	int size;
};

struct data_center {
	vector<video_dc> videos;
};

struct video {
	int id;
	int requested;
};

struct conexion_cache {
	int id;
	int latencia_a_cache;
};
