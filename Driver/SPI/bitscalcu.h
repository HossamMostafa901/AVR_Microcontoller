#ifndef bitscalcu
#define bitscalcu

# define set_bit(var,bitno) (var)|=(1<<(bitno))

# define clear_bit(var,bitno) (var)&=(~(1<<(bitno)))

# define togle_bit(var,bitno) (var)^=(1<<(bitno))

# define get_bit(var,bitno) (((var)>>(bitno))&(1))

# define assign_bit(var,bitno,Value) do{\
										if(Value==1)\
											set_bit(var,bitno);\
										else\
											clear_bit(var,bitno);\
									}while(0)
	
#endif