province_set = {'河北省', '山西省', '辽宁省', '吉林省', '黑龙江省', '江苏省', '浙江省', \
                 '安徽省', '福建省', '江西省', '山东省', '台湾省', '河南省', '湖北省', '湖南省',\
                 '广东省', '海南省'}

# 请使用for循环输出province_set中所有省份

for i in province_set:
    print(i)

# 请增加“台湾”省到province_set中
province_set.add("台湾")

# 请用户输入一个省份名称，判断是否在province_set中，输出：xx在/不在集合中
# 需要支持用户输入“辽宁”不带“省”字的情况

key = input("Input : ")
if "省" not in key:
    key += '省'
if key in province_set:
    print("{}在集合中".format(key))
else:
    print("{}不在集合中".format(key))

province_set2 = { '河南省', '湖北省', '湖南省','广东省', '海南省', '四川省', '贵州省', \
                             '云南省', '陕西省', '甘肃省', '青海省'}

# 请输出province_set和province_set2合并后的结果，每个省份之间用空格隔开
for i in province_set|province_set2:
    print(i, end=' ')
print()

# 请输出province_set和province_set2中共有的省份，每个省份之间用空格隔开
for i in province_set&province_set2:
    print(i, end=' ')
print()


# 请输出province_set中有，但province_set2中没有的省份，每个省份之间用空格隔开
for i in province_set:
    if i not in province_set2:
        print(i, end=' ')
print()
            
