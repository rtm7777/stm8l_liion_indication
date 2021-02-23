#define ARR_Val ((uint16_t)124)
#define Delay_Val ((uint16_t)500)
#define Toggle_Delay_Val ((uint16_t)400)

static void TIM2_Config(void);
static void GPIO_Config(void);

void Start_Welding(void);
void Stop_Welding(void);

void Delay (uint16_t nCount);
