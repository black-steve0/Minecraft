#pragma once

#include "engine.h"

stv::Vector3 prespective;

namespace gme {

	void createChunk(int position = 0) {
		stv::matrix3d chunk(16, 16, 16);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 16; j++) {
				for (int k = 0; k < 16; k++) {
					chunk.data[i][j][k] = 1;
				}
			}
		}

		chunks.push_back(chunk);
	}

	void loadChunk(int chunkid = 0) {
		int size = 50;
		stv::matrix3d chunk = chunks[chunkid];

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 16; j++) {
				for (int k = 0; k < 16; k++) {
					if (chunk.data[i][j][k] == 1) {
						geo::cube(stv::Vector3(size*k, size*j, size*i), stv::Vector3(150, 150, 150), stv::rgb(0, 0, 0), prespective);
					}
				}
			}
		}
		
	}

}