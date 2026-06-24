#include "pch.h"
#include "Vector3.h"

TEST(Vector3Tests, MemoryAlignment) {
	EXPECT_EQ(sizeof(Vector3<float>), 16);
}

TEST(Vector3Tests, DefaultInitialization) {
	Vector3<float> v;
	EXPECT_EQ(v.x, 0.0f);
	EXPECT_EQ(v.y, 0.0f);
	EXPECT_EQ(v.z, 0.0f);
}

TEST(Vector3Tests, Addition) {
	Vector3<float> v1 = { 1.0f, 2.0f, 3.0f };
	Vector3<float> v2 = { 4.0f, 5.0f, 6.0f };

	Vector3<float> v3 = v1 + v2;
	v1 += v2;

	// Test v1 is updated
	EXPECT_NEAR(v1.x, 5.0f, 0.0001f);
	EXPECT_NEAR(v1.y, 7.0f, 0.0001f);
	EXPECT_NEAR(v1.z, 9.0f, 0.0001f);

	// Test v2 is unchanged
	EXPECT_NEAR(v2.x, 4.0f, 0.0001f);
	EXPECT_NEAR(v2.y, 5.0f, 0.0001f);
	EXPECT_NEAR(v2.z, 6.0f, 0.0001f);

	// Test v3 is updated
	EXPECT_NEAR(v3.x, 5.0f, 0.0001f);
	EXPECT_NEAR(v3.y, 7.0f, 0.0001f);
	EXPECT_NEAR(v3.z, 9.0f, 0.0001f);
}

TEST(Vector3Tests, ScalarMultiplication) {
	Vector3<float> v1 = { 1.0f, 2.0f, 3.0f };

	Vector3<float> v2 = v1 * 2.0f;
	Vector3<float> v3 = 2.0f * v1;

	v1 *= 2.0f;

	// Test v1 is updated
	EXPECT_NEAR(v1.x, 2.0f, 0.0001f);
	EXPECT_NEAR(v1.y, 4.0f, 0.0001f);
	EXPECT_NEAR(v1.z, 6.0f, 0.0001f);

	// Test v2 is updated
	EXPECT_NEAR(v2.x, 2.0f, 0.0001f);
	EXPECT_NEAR(v2.y, 4.0f, 0.0001f);
	EXPECT_NEAR(v2.z, 6.0f, 0.0001f);

	// Test v3 is updated
	EXPECT_NEAR(v3.x, 2.0f, 0.0001f);
	EXPECT_NEAR(v3.y, 4.0f, 0.0001f);
	EXPECT_NEAR(v3.z, 6.0f, 0.0001f);
}

TEST(Vector3Tests, DotProduct) {
	Vector3<double> v1 = { 1.0, 2.0, 3.0 };
	Vector3<double> v2 = { 4.0, 5.0, 6.0 };

	double result = dot(v1, v2);
	EXPECT_NEAR(result, 32.0, 0.0001);
}

TEST(Vector3Tests, Division) {
	Vector3<double> v1 = { 1.0, 2.0, 3.0 };
	v1 /= 2.0f;
	Vector3<double> v2 = v1 / 0.5;
	
	//Test v1 is updated
	EXPECT_NEAR(v1.x, 0.5, 0.0001);
	EXPECT_NEAR(v1.y, 1.0, 0.0001);
	EXPECT_NEAR(v1.z, 1.5, 0.0001);

	//Test v2 is updated
	EXPECT_NEAR(v2.x, 1.0, 0.0001);
	EXPECT_NEAR(v2.y, 2.0, 0.0001);
	EXPECT_NEAR(v2.z, 3.0, 0.0001);
}

TEST(Vector3Tests, Length) {
	Vector3<float> v1 = { 1.0f, 2.0f, 3.0f };
	Vector3<double> v2 = { 4.0, 5.0, 6.0 };

	float result_v1 = v1.length();
	double result_v2 = v2.length();

	EXPECT_NEAR(result_v1, 3.7417f, 0.0001f);
	EXPECT_NEAR(result_v2, 8.77496, 0.0001);
}

TEST(Vector3Tests, Cross) {
	Vector3<float> v1 = { 1.0f, 2.0f, 3.0f };
	Vector3<float> v2 = { 4.0f, 5.0f, 6.0f };

	Vector3<float> result = cross(v1, v2);	

	EXPECT_NEAR(result.x, -3.0f, 0.0001);
	EXPECT_NEAR(result.y, 6.0f, 0.0001);
	EXPECT_NEAR(result.z, -3.0f, 0.0001);
}

TEST(Vector3Tests, Subtraction) {
	Vector3<float> v1 = { 1.0f, 2.0f, 3.0f };
	Vector3<float> v2 = { 4.0f, 5.0f, 6.0f };

	Vector3<float> v3 = v1 - v2;
	v1 -= v2;

	// Test v1 is updated
	EXPECT_NEAR(v1.x, -3.0f, 0.0001f);
	EXPECT_NEAR(v1.y, -3.0f, 0.0001f);
	EXPECT_NEAR(v1.z, -3.0f, 0.0001f);

	// Test v2 is unchanged
	EXPECT_NEAR(v2.x, 4.0f, 0.0001f);
	EXPECT_NEAR(v2.y, 5.0f, 0.0001f);
	EXPECT_NEAR(v2.z, 6.0f, 0.0001f);

	// Test v3 is updated
	EXPECT_NEAR(v3.x, -3.0f, 0.0001f);
	EXPECT_NEAR(v3.y, -3.0f, 0.0001f);
	EXPECT_NEAR(v3.z, -3.0f, 0.0001f);
}

TEST(Vector3Tests, Negation) {
	Vector3<double> v1 = { -1.0, 2.0, 3.0 };
	
	Vector3<double> result = -v1;
	EXPECT_EQ(result.x, 1.0);
	EXPECT_EQ(result.y, -2.0);
	EXPECT_EQ(result.z, -3.0);
}


