	#define UART1_TX (1 << 16)
	#define UART1_RX (1 << 18)
	#define UART0_TX (1 << 0)
	#define UART0_RX (1 << 2)
	#define UART1_GSM_ALL (UART1_TX | UART1_RX)
	#define UART0_GSM_ALL (UART0_TX | UART0_RX)
	


void GSM_UART1_init(void);
void GPS_UART0_init(void);

void string_uart_trns_gsm(char *str);

void string_uart_trns_gps(char *str);

void put_char_gsm(char c);

void put_char_gps(char c);

char uart_recv_gsm(void);

char uart0_recv_gps(void);

void gsm_response(char ca,int no);



void gsm_send_msg(char *str1,char *str2,char *str3);
