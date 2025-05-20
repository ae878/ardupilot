
#define TEST_CONF 1

#if TEST_CONF == 1
#define TEST_NESTED_DEFINE 1
#endif

#if TEST_CONF == 2
#define TEST_NESTED_DEFINE 2
#endif


#define SIBLING_CONFIG 1