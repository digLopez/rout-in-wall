# 运行步骤

1. **运行Q3.out or Q3.exe**

	> linux中 
	> 
	> g++ main.cpp -o Q3.out --std=c++11
	> 
	> ./Q3.out
	> 
	> 或者
	> 
	> windows中 ./Q3.exe

2. **输入方式**

	- 正确方式输入（第一行矩阵大小，第二行连通性描述）会输出表格；

	- 错误的输入需要输入两行（到达两个 ‘\n’），才会输出对应的错误信息

# 编程思路

## 功能分布

1. 输入

2. 正则（分为对**输入的格式**正则 和 对**数值有效性**正则）

3. 生成矩阵

4. 输出

## 代码结构

1. 获取输入的方式


	
		```

		while (temp=cin.get()) {

			string str1 = {temp};

		    while (temp=cin.get(),temp != '\n')

    			str1 += temp;
		
			string str2("");
	
			while (temp=cin.get(),temp != '\n')

    			str2 += temp;
	
		}

		```

	

2. 正则pattern


		```
	
		#include <regex>
	
		regex reg1("\\d+\\s\\d+");
	
		//将第二行的每个小节单独正则
	
		regex reg2("\\d+,\\d+ \\d+,\\d+");

		```
	
	

3. 生成矩阵

	将输入的边通过**映射**的方式保存到矩阵对应的位置


		```
		class edge {
	
		public:
	
	  		int middlea() {
	
	   			return (first.geta()+second.geta())+1;
	
	    	}
	
		privete:
	
	    	point first;
	
	    	point second;
	
		};
	
		edge e(a, b, c, d);
	
		matrix[e.middlea()][e.middleb()]='R';
	
		```
	


4. 输出

		```
	
		if (mark)
	
	    	output(matrix);

		``
	
	