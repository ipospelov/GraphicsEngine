#pragma once


class MathUtils
{
public:
	
	static const Matrix4x4 GetMatrixWorldViewProjT(const Matrix4x4 & matWorld, const Matrix4x4 & matView, const Matrix4x4 & matProj)
	{
		Matrix4x4 matWorldViewProj = matWorld * matView * matProj;

		Matrix4x4 matWorldViewProjT = matWorldViewProj.Transpose();

		return matWorldViewProjT;
	}

	
	static const Matrix4x4 GetMatrixTranspose(const Matrix4x4 & mat)
	{
		Matrix4x4 matT = mat.Transpose();	
		
		return matT;
	}

	static const Matrix4x4 GetMatrixInverse(const Matrix4x4 & mat)
	{
		Matrix4x4 matInverse = mat.Inverse();
		
		return matInverse;
	}
};