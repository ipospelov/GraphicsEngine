#include "MeshObjFile.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


//// A structure for our custom vertex type
//struct CUSTOMVERTEX
//{
//	FLOAT x, y, z;
//	FLOAT nx, ny, nz;
//	DWORD color;
//	FLOAT u1, v1;
//};
//
//bool ConstructCustomVertex(CUSTOMVERTEX & out, 
//						   size_t pIdx, const std::vector<Vector3> & vertices, 
//						   size_t nIdx, const std::vector<Vector3> & normals, 
//						   size_t tIdx, const std::vector<D3DXVECTOR2> & textCoords)
//{
//	pIdx = pIdx - 1;
//	nIdx = nIdx - 1;
//	tIdx = tIdx - 1;
//
//	if (pIdx < vertices.size() && nIdx < normals.size() && tIdx < textCoords.size())
//	{
//		Vector3 position	= vertices  [pIdx];
//		Vector3 normal		= normals   [nIdx];
//		D3DXVECTOR2 uv1		= textCoords[tIdx];
//			
//		out.x	= position.x;
//		out.y	= position.y;
//		out.z	= position.z;
//			
//		out.u1	= uv1.x;
//		out.v1	= uv1.y;
//			
//		out.nx	= normal.x;
//		out.ny	= normal.y;
//		out.nz	= normal.z;
//
//		return true;
//	}
//
//	return false;
//}
//
//// Our custom FVF, which describes our custom vertex structure
//#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE | D3DFVF_TEX1 | D3DFVF_TEXCOORDSIZE4(0))
//
//MeshObjFile::MeshObjFile(LPCWSTR pFilepath)
//{
//	m_pFilepath = pFilepath;
//}
//
//void MeshObjFile::Init()
//{
//	ReadAllTriangles();
//
//	std::vector<CUSTOMVERTEX> vertices;
//	std::vector<int> indices;
//	int curIdx = 0;
//	
//	for (size_t i = 0; i < m_triangles.size(); ++i)
//	{
//		TriangleInObjFile t = m_triangles[i];
//		
//		CUSTOMVERTEX v1, v2, v3;
//
//		bool b1 = ConstructCustomVertex(v1, t.v1Idx, m_vertices, t.n1Idx, m_normals, t.t1Idx, m_textCoords);
//		bool b2 = ConstructCustomVertex(v2, t.v2Idx, m_vertices, t.n2Idx, m_normals, t.t2Idx, m_textCoords);
//		bool b3 = ConstructCustomVertex(v3, t.v3Idx, m_vertices, t.n3Idx, m_normals, t.t3Idx, m_textCoords);
//
//		if (b1 && b2 && b3)
//		{
//			vertices.push_back(v1);
//			vertices.push_back(v2);
//			vertices.push_back(v3);
//
//			indices.push_back(curIdx++);
//			indices.push_back(curIdx++);
//			indices.push_back(curIdx++);
//		}
//
//		if (i == 0)
//		{
//			break;
//		}
//	}
//
//	HRESULT result = Mesh::Init();
//
//	result &= CreateVertexBuffer(&vertices[0], vertices.size() * sizeof(CUSTOMVERTEX), vertices.size(), D3DFVF_CUSTOMVERTEX);
//	result &= CreateIndexBuffer (&indices[0],  indices.size() * sizeof(int), indices.size(), D3DPT_TRIANGLELIST);
//}
//
//void MeshObjFile::Deinit()
//{
//	Mesh::Deinit();
//}
//
//void MeshObjFile::ReadAllTriangles()
//{
//	std::ifstream file;
//	file.open(m_pFilepath);
//	
//	const std::string vPosition("v ");
//	const std::string vNormal("vn");
//	const std::string vTextureCoords("vt");
//	const std::string vTriangle("f ");
//	std::string line;
//	
//	if (file.is_open())
//	{
//		while (std::getline(file, line))
//		{
//			if (line.length() < 2) continue;
//
//			std::string cmd = line.substr(0, 2);
//			if (cmd == vPosition)
//			{
//				// Пример строки cmd: "v -0.5 -0.5 0.5"
//				std::string posStr = line.substr(2);
//				Vector3 pos;
//
//				if (ReadVector3(posStr, pos))
//				{
//					m_vertices.push_back(pos);
//				}
//			}
//			else if (cmd == vNormal)
//			{
//				// Пример строки cmd: "vn 0 0 1"
//				std::string normalStr = line.substr(2);
//				Vector3 normal;
//
//				if (ReadVector3(normalStr, normal))
//				{
//					m_normals.push_back(normal);
//				}
//			}
//			else if (cmd == vTextureCoords)
//			{
//				// Пример строки cmd: "vt 0 0"
//				std::string textCoordsStr = line.substr(2);
//				D3DXVECTOR2 textCoords;
//
//				if (ReadVector2(textCoordsStr, textCoords))
//				{
//					m_textCoords.push_back(textCoords);
//				}
//			}
//			else if (cmd == vTriangle)
//			{
//				// Пример строки cmd: "f 2/2/2 4/4/4 1/1/1"
//				std::string triangleStr = line.substr(2);
//				TriangleInObjFile triangle;
//
//				if (ReadTriangle(triangleStr, triangle))
//				{
//					m_triangles.push_back(triangle);
//				}
//			}
//		}
//
//		file.close();
//	}
//}
//
//bool MeshObjFile::ReadVector3(const std::string & line, Vector3 & vec)
//{
//	// Пример строки: "-0.5 -0.5 0.5"
//	std::stringstream ss(line);
//
//	try
//	{
//		ss >> vec.x >> vec.y >> vec.z;
//	}
//	catch (...)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//bool MeshObjFile::ReadVector2(const std::string & line, D3DXVECTOR2 & vec)
//{
//	// Пример строки: "0 0"
//	std::stringstream ss(line);
//
//	try
//	{
//		ss >> vec.x >> vec.y;
//	}
//	catch (...)
//	{
//		return false;
//	}
//
//	return true;
//}
//
//bool MeshObjFile::ReadTriangle(const std::string & line, TriangleInObjFile & triangle)
//{
//	// Пример строки: "2/2/2 4/4/4 1/1/1"
//	std::stringstream ss(line);
//
//	try
//	{
//		char ch;
//
//		ss >> triangle.v1Idx >> ch >> triangle.t1Idx >> ch >> triangle.n1Idx;
//		ss >> triangle.v2Idx >> ch >> triangle.t2Idx >> ch >> triangle.n2Idx;
//		ss >> triangle.v3Idx >> ch >> triangle.t3Idx >> ch >> triangle.n3Idx;
//	}
//	catch (...)
//	{
//		return false;
//	}
//
//	return true;
//}
