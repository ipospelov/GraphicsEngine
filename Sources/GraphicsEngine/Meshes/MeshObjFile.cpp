#include "MeshObjFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


// Our custom FVF, which describes our custom vertex structure
#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE4(0))

MeshObjFile::MeshObjFile(LPCWSTR pFilepath)
{
	m_pFilepath = pFilepath;
}

void MeshObjFile::Init()
{
	ReadAllTriangles();


    std::vector<int> indices;
   // std::cout<<indices.size()<<std::endl;
    for (int i = 0; i < m_triangles.size(); ++i)
    {
        indices.push_back(--m_triangles[i].v1Idx);

        indices.push_back(--m_triangles[i].v2Idx);

        indices.push_back(--m_triangles[i].v3Idx);
        //indices.push_back(i);
    }
    //indices.resize(30);
/*    std::cout<<indices.size()<<std::endl;
    std::cout<<m_vertices.size()<<std::endl;
    std::cout<<m_normals.size()<<std::endl;
    std::cout<<m_triangles.size()<<std::endl;*/
    //
    Mesh::Init();
    meshImpl->SetVertices(m_vertices);

   // meshImpl->SetColors(colors);
    meshImpl->SetNormals(m_normals);
/*
    for(int i =0; i< m_textCoords.size(); i++){
        std::cout<<m_textCoords[i].x<<" "<< m_textCoords[i].y<<" "<< m_textCoords[i].z<<std::endl;
    }
*/

    meshImpl->SetUV0(m_textCoords);
    meshImpl->SetIndices(indices, MESH_TOPOLOGY_TRIANGLE_LIST);//MESH_TOPOLOGY_TRIANGLE_STRIP);
    meshImpl->Apply();
}

void MeshObjFile::Deinit()
{
	Mesh::Deinit();
}

void MeshObjFile::ReadAllTriangles()
{
	std::ifstream file;
	file.open(m_pFilepath);

	const std::string vPosition("v ");
	const std::string vNormal("vn");
	const std::string vTextureCoords("vt");
	const std::string vTriangle("f ");
	std::string line;

	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (line.length() < 2) continue;

			std::string cmd = line.substr(0, 2);
			if (cmd == vPosition)
			{
				// Пример строки cmd: "v -0.5 -0.5 0.5"
				std::string posStr = line.substr(2);
				Vector3 pos;

				if (ReadVector3(posStr, pos))
				{
					m_vertices.push_back(pos);
				}
			}
			else if (cmd == vNormal)
			{
				// Пример строки cmd: "vn 0 0 1"
				std::string normalStr = line.substr(2);
				Vector3 normal;

				if (ReadVector3(normalStr, normal))
				{
					m_normals.push_back(normal);
				}
			}
			else if (cmd == vTextureCoords)
			{
				// Пример строки cmd: "vt 0 0"
				std::string textCoordsStr = line.substr(2);
				Vector3 textCoords;

				if (ReadShortVector3(textCoordsStr, textCoords))
				{
					m_textCoords.push_back(textCoords);
				}
			}
			else if (cmd == vTriangle)
			{
				// Пример строки cmd: "f 2/2/2 4/4/4 1/1/1"
				std::string triangleStr = line.substr(2);
				TriangleInObjFile triangle;

				if (ReadTriangle(triangleStr, triangle))
				{
					m_triangles.push_back(triangle);
				}
			}
		}

		file.close();
	}
}

bool MeshObjFile::ReadVector3(const std::string & line, Vector3 & vec)
{
	// Пример строки: "-0.5 -0.5 0.5"
	std::stringstream ss(line);

	try
	{
		ss >> vec.x >> vec.y >> vec.z;
	}
	catch (...)
	{
		return false;
	}

	return true;
}

bool MeshObjFile::ReadShortVector3(const std::string & line, Vector3 & vec)
{
	// Пример строки: "0 0"
	std::stringstream ss(line);

	try
	{
		ss >> vec.x >> vec.y;
        vec.z = 0;
	}
	catch (...)
	{
		return false;
	}

	return true;
}

bool MeshObjFile::ReadTriangle(const std::string & line, TriangleInObjFile & triangle)
{
	// Пример строки: "2/2/2 4/4/4 1/1/1"
	std::stringstream ss(line);

	try
	{
		char ch;

		ss >> triangle.v1Idx >> ch >> triangle.t1Idx >> ch >> triangle.n1Idx;
		ss >> triangle.v2Idx >> ch >> triangle.t2Idx >> ch >> triangle.n2Idx;
		ss >> triangle.v3Idx >> ch >> triangle.t3Idx >> ch >> triangle.n3Idx;
	}
	catch (...)
	{
		return false;
	}

	return true;
}
