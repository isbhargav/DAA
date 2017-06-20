vector<int> div(int n)
{
	vector<int> v;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(!(n/i))
		{
			if(i==sqrt(n))
				v.push_back(i);
			else
			{
				v.push_back(i);
				v.push_back(n/i);
			}

		}
	}
	return v;
}