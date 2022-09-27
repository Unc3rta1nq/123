#include <iostream>
#include <filesystem>
#include <vector>
#include <string>


using namespace std;
using namespace filesystem;

int main()
{
	vector<string> FName;
	vector<int> FSize;
	string DirName, sub_name;
	path way;
	path _way;
	path fileWay;
	int n = 0, file_point = 0, tmp = 0, I=49;

	cout << "Enter way: ";
	cin >> DirName;
	way = DirName;
	_way = DirName;

	for (auto& p : directory_iterator(way))
	{
		way = p.path();
		FName.push_back(way.string());
		FSize.push_back(p.file_size());
		way.remove_filename();
		n++;
	}

	for (int i = 0; i < n; ++i) 
	{
		cout << FName[i] << " || SIZE ==> "<< FSize[i] /1024 << "Kb" << endl;
	}

	way.remove_filename();
	
	for (int i = 0; i < n; i++)
	{
		if (tmp >= 100 || FSize[i] / 1024 + tmp > 100)
		{
			file_point = 0;
			tmp = 0;
		}
		if (FSize[i]/1024 > 100)
		{
			way.remove_filename();
			way = _way;
			DirName = "DIR";
			sub_name = I++;
			DirName = DirName + sub_name;
			way /= DirName;
			
			create_directory(way.string());
			fileWay.remove_filename();
			fileWay = _way;
			fileWay /= FName[i];
			copy(fileWay.string(), way.string());
		}
		else if (tmp < 100)
		{
			if (file_point == 0)
			{
				way.remove_filename();
				way = _way;
				DirName = "DIR";
				sub_name = I++;
				DirName = DirName + sub_name;
				way /= DirName;
				create_directory(way.string());
				file_point = 1;
			}
			fileWay.remove_filename();
			fileWay = _way;
			fileWay /= FName[i];
			copy(fileWay.string(), way.string());
			tmp = tmp + FSize[i]/1024;
		}
	}

	system("pause");
	return 0;
}