string postfix(string str)
{
	stack<ll> st;
	string str1;
	map<char,ll> mp;
	mp['^'] = 3;
	mp['*'] = 2;
	mp['/'] = 2;
	mp['+'] = 1;
	mp['-'] = 1;
	mp['('] = 4;
	mp[')'] = 0;
	for(ll i=0;i<str.length();i++)
	{
		if(str[i] == '(')
			st.push('(');
		else if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= '0' && str[i] <= '9'))
		{
			str1 += str[i];
			str1 += " ";
		}
		else if(str[i] == ')')
		{
			while(st.top() != '(')
			{
				str1 += st.top();
				str1 += " ";
				st.pop();
			}
			st.pop();
		}
		else
		{
			while((st.size()) && (st.top() != '(') && (mp[st.top()] >= mp[str[i]]))
			{
				str1 += st.top();
				str1 += " ";
				st.pop();
			}
			st.push(str[i]);
		}
	}
	while(!st.empty())
	{
		str1 += st.top();
		str1 += " ";
		st.pop();
	}
	return str1;
}

ll postfixResult(string str)
{
	stack<ll> st;
	for(ll i=0;i<str.length();i+=2)
	{
		if((str[i] >= '0' && str[i] <= '9'))
			st.push((ll)(str[i]-'0'));
		else
		{
			ll k = st.top();
			st.pop();
			ll l = st.top();
			st.pop();
			if(str[i] == '+')
				st.push(l+k);
			else if(str[i] == '-')
				st.push(l-k);
			else if(str[i] == '*')
				st.push(l*k);
			else if(str[i] == '/')
				st.push(l/k);
		}
	}
	ll data = st.top();
	st.pop();
	return data;
}