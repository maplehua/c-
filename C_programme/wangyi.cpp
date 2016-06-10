
#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(void) {

	int s;
	while (cin>>s) {
		vector<string> res;
		while (s > 0) {
			s--;
			int arr[3][3];
			int x_num = 0, o_num = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
				{
					char c;
					cin>>c;
					switch(c) {
					case 'O':
						arr[i][j] = 1; o_num++;break;
					case 'X':
						arr[i][j] = -1;x_num++;break;
					case '_':
						arr[i][j] = 0;break;
					}
				}
			if (x_num < o_num) {
				//cout<<"Invalid"<<endl;
				res.push_back("Invalid");
				continue;
			}
			if (x_num + o_num == 9) {
				bool x_flag = false;
				bool o_flag = false;
				for (int i = 0; i < 3; i++) {
					int tmp_sum = 0;
				    for (int j = 0; j < 3; j++)
						tmp_sum += arr[i][j];
					if (tmp_sum == -3)
						x_flag = true;
					else if(tmp_sum == -3)
						o_flag = true;
				}
				for (int i = 0; i < 3; i++) {
					int tmp_sum = 0;
				    for (int j = 0; j < 3; j++)
						tmp_sum += arr[j][i];
					if (tmp_sum == -3)
						x_flag = true;
					else if(tmp_sum == -3)
						o_flag = true;
				}
				int tmp_sum = arr[0][0] + arr[1][1] + arr[2][2];
				if (tmp_sum == -3)
						x_flag = true;
					else if(tmp_sum == -3)
						o_flag = true;
				tmp_sum = arr[0][2] + arr[1][1] + arr[2][0];
				if (tmp_sum == -3)
						x_flag = true;
					else if(tmp_sum == -3)
						o_flag = true;
				if (x_flag == true && o_flag == true)
				{
				    //cout<<"Invalid"<<endl;
					res.push_back("Invalid");
				    continue;
				} else if (x_flag) {
					//cout<<"X win"<<endl;
					res.push_back("X win");
				    continue;
				} else if (o_flag) {
				    //cout<<"O win"<<endl;
					res.push_back("O win");
				    continue;
				} else {
					//cout<<"Draw"<<endl;
					res.push_back("Draw");
				    continue;
				}
				continue;
			} 
			
			if (x_num + o_num < 9) {
				bool flag = false;
				if (x_num == o_num) {
					for (int i = 0; i < 3; i++) {
						int tmp_sum = 0;
						for (int j = 0; j < 3; j++)
							tmp_sum += arr[i][j];
						if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");flag = true;break;
						} else if (tmp_sum == 3) {
							//cout<<"O win"<<endl;
							res.push_back("O win");
							flag = true;break;}

						else if (tmp_sum == -2) {
							//cout<<"Next win"<<endl;
							res.push_back("Next win");
							flag = true;break;
						}
						
					}

					for (int i = 0; i < 3; i++) {
						int tmp_sum = 0;
						for (int j = 0; j < 3; j++)
							tmp_sum += arr[j][i];

						if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
							flag = true;break;
						} else if (tmp_sum == 3) {
							//cout<<"O win"<<endl;
							res.push_back("O win");
							flag = true;break;}

						else if (tmp_sum == -2) {
							//cout<<"Next win"<<endl;
							res.push_back("Next win");
							flag = true;break;
						}
					}

					int tmp_sum = arr[0][0] + arr[1][1] + arr[2][2];

					if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
							flag = true;break;
						} else if (tmp_sum == 3) {
							//cout<<"O win"<<endl;
							res.push_back("O win");
							flag = true;break;}

					else if (tmp_sum == -2) {
							//cout<<"Next win"<<endl;
							res.push_back("Next win");
							flag = true;break;
						}
					tmp_sum = arr[0][2] + arr[1][1] + arr[2][0];

					if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
						} else if (tmp_sum == 3) {
							//cout<<"O win"<<endl;
					        res.push_back("O win");
					}

					else if (tmp_sum == -2) {
							//cout<<"Next win"<<endl;
							res.push_back("Next win");
						}
				} 


				else if (x_num > o_num) {
					for (int i = 0; i < 3; i++) {
							int tmp_sum = 0;
							for (int j = 0; j < 3; j++)
								tmp_sum += arr[i][j];
							

							if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
							flag = true;break;
						    } else if (tmp_sum == 3){
								//cout<<"O win"<<endl;
								res.push_back("O win");
								flag = true;break;}
                           else if (tmp_sum == 2) {
								//cout<<"Next win"<<endl;
								res.push_back("Next win");
								flag = true;break;
							}
						}

						for (int i = 0; i < 3; i++) {
							int tmp_sum = 0;
							for (int j = 0; j < 3; j++)
								tmp_sum += arr[j][i];

							if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
							flag = true;break;
						    } else if (tmp_sum == 3) {
								//cout<<"O win"<<endl;
								res.push_back("O win");
								flag = true;break;}

							else if (tmp_sum == 2) {
								//cout<<"Next win"<<endl;
								res.push_back("Next win");
								flag = true;break;
							}
						}

						int tmp_sum = arr[0][0] + arr[1][1] + arr[2][2];
						

						if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
						} else if (tmp_sum == 3)
							//cout<<"O win"<<endl;
						   res.push_back("O win");
						else if (tmp_sum == 2) {
								//cout<<"Next win"<<endl;
								res.push_back("Next win");
							}
						tmp_sum = arr[0][2] + arr[1][1] + arr[2][0];
						

						if (tmp_sum == -3) {
							//cout<<"X win"<<endl;
							res.push_back("X win");
						} else if (tmp_sum == 3)
							//cout<<"O win"<<endl;
						    res.push_back("O win");
						else if (tmp_sum == 2) {
								//cout<<"Next win"<<endl;
								res.push_back("Next win");
							}
				
				} 
				
			if (!flag)
				//cout<<"Next cannot win"<<endl;
				res.push_back("Next cannot win");
			}
		 
				
		}
		vector<string>::iterator iter = res.begin();
		while (iter != res.end()) {
			cout<<*iter<<endl;
			iter++;
		}
	}

	return 0;
}
