import pandas as pd

pd.set_option('display.unicode.ambiguous_as_wide', True)
pd.set_option('display.unicode.east_asian_width', True)

df = pd.read_excel('超市营业额2.xlsx')

print('下标在[5,10]区间的行'.ljust(20,'='), df[5:11], sep='\n')
# iloc使用整数做索引
print('索引为5的行'.ljust(20,'='), df.iloc[5], sep='\n')
print('下标为[3,5,10]的行'.ljust(20,'='), df.iloc[[3,5,10],:], sep='\n')
print('行下标为[3,5,10], 列下标为[0,1,4]'.ljust(30,'='))
print(df.iloc[[3,5,10],[0,1,4]])
print('查看指定的列前5行'.ljust(20,'='))
print(df[['姓名', '时段', '交易额']][1:5])
print('只查看前10行指定的列'.ljust(20,'='))
print(df[:10][['姓名', '日期', '柜台']])
print('下标为[3,5,10]的行的指定列'.ljust(20,'='))
# loc和at使用标签做索引
print(df.loc[[3,5,10], ['姓名','交易额']])

print('行下标为3, 姓名列的值'.ljust(20,'='), df.at[3, '姓名'], sep='\n')
print('交易额高于1700元的数据'.ljust(20,'='), df[df['交易额']>1700], sep='\n')
print('交易总额'.ljust(20,'='), df['交易额'].sum(), sep='\n')
print('下午班的交易总额'.ljust(20,'='))
print(df[df['时段']=='14:00~21:00']['交易额'].sum())
print('张三下午班的交易情况'.ljust(20,'='))
print(df[(df.姓名 == '张三') & (df.时段 =='14:00~21:00')][:10])
print('日用品柜台销售总额'.ljust(20,'='))
print(df[df['柜台']=='日用品']['交易额'].sum())
print('张三和李四2人销售总额'.ljust(20,'='))
print(df[df['姓名'].isin(['张三','李四'])]['交易额'].sum())
print('交易额在指定范围内的记录'.ljust(20,'='))
print(df[df['交易额'].between(800,850)])