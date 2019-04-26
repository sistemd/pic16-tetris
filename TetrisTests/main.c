#include "CUnit.h"
#include "Basic.h"
#include "MovementTests.h"
#include "RotationTests.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	if (CU_initialize_registry() != CUE_SUCCESS)
		printf("An error happened.\n");

	CU_TestInfo movementTests[] = {
		{ "Movement Left and Right", TestMovementLeftRight },
		CU_TEST_INFO_NULL,
	};

	CU_TestInfo rotationTests[] = {
		{ "Rotation", TestRotation },
		CU_TEST_INFO_NULL,
	};

	CU_SuiteInfo suites[] = {
		{ "Movement Tests", NULL, NULL, NULL, NULL, movementTests },
		{ "Rotation Tests", NULL, NULL, NULL, NULL, rotationTests },
		CU_SUITE_INFO_NULL,
	};

	if (CU_register_suites(suites) != CUE_SUCCESS || CU_basic_run_tests() != CUE_SUCCESS)
		printf("An error happened.\n");
}
