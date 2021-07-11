#include "pch.h"
#include "CppUnitTest.h"

#include <stdio.h>
#define _USE_MATH_DEFINES // for C++
#include <cmath>
#include <math.h> 


#include <MapManager.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace TheWorld_MapManager;

namespace TheWorldMapManagerUnitTest
{
	TEST_CLASS(TheWorldMapManagerUnitTest)
	{
	public:
		
		TEST_METHOD(TestMethodCreateWD)
		{
			float posX = 2;
			float posZ = 3;
			float radiusResulting = (float)3.60555124;
			float azimuthResulting = (float)0.982793748;
			float azimuthDegreeResulting = (float)56.3099327;

			WorldDefiner WD1(posX, posZ, WDType::elevator, 0.5, 5000);
			float radius = WD1.getRadius();
			float azimuth = WD1.getAzimuth();
			float azimuthDegree = WD1.getAzimuthDegree();
			Assert::AreEqual(radius, radiusResulting, radius / 1000000);
			Assert::AreEqual(azimuth, azimuthResulting, azimuth / 1000000);
			Assert::AreEqual(azimuthDegree, azimuthDegreeResulting, azimuthDegree / 1000000);

			WorldDefiner WD2(-posX, posZ, WDType::elevator, 0.5, 5000);
			radius = WD2.getRadius();
			azimuth = WD2.getAzimuth();
			azimuthDegree = WD2.getAzimuthDegree();
			Assert::AreEqual(radius, radiusResulting, radius / 1000000);
			Assert::AreEqual(azimuth, (float)M_PI - azimuthResulting, azimuth / 1000000);
			Assert::AreEqual(azimuthDegree, (float)180 - azimuthDegreeResulting, azimuthDegree / 1000000);

			WorldDefiner WD3(-posX, -posZ, WDType::elevator, 0.5, 5000);
			radius = WD3.getRadius();
			azimuth = WD3.getAzimuth();
			azimuthDegree = WD3.getAzimuthDegree();
			Assert::AreEqual(radius, radiusResulting, radius / 1000000);
			Assert::AreEqual(azimuth, (float)M_PI + azimuthResulting, azimuth / 1000000);
			Assert::AreEqual(azimuthDegree, (float)180 + azimuthDegreeResulting, azimuthDegree / 1000000);

			WorldDefiner WD4(posX, -posZ, WDType::elevator, 0.5, 5000);
			radius = WD4.getRadius();
			azimuth = WD4.getAzimuth();
			azimuthDegree = WD4.getAzimuthDegree();
			Assert::AreEqual(radius, radiusResulting, radius / 1000000);
			Assert::AreEqual(azimuth, (float)M_PI * 2 - azimuthResulting, azimuth / 1000000);
			Assert::AreEqual(azimuthDegree, (float)360 - azimuthDegreeResulting, azimuthDegree / 1000000);
		}
	};
}
