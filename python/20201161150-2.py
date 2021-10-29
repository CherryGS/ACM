province_dict = {"辽宁省":"沈阳","吉林省":"长春","黑龙江省":"哈尔滨","安徽省":"合肥"}

# 通过访问province_dict打印出吉林省的省会城市
print(province_dict["吉林省"])

# 请将辽宁省省会修改为“大沈阳”
province_dict["辽宁省"] = "大沈阳"

# 增加山东省省会济南到province_dict中
province_dict["山东省"] = "济南"

# 请删除安徽省及省会信息
del province_dict['安徽省']

# 用for循环输出provice_dict中所有省份和省会城市，每个省份和省会一行，中间用冒号分割
for i in province_dict.items():
    print(i[0], ':', i[1])

# 请用户输入一个省份名称，判断是否在province_set中
# 如果用户输入的不在字典中，提示“暂未收录该省份的省会信息”
# 如果在字典中，则输出“xx省的省会是xx”
# 需要支持用户输入“辽宁”不带“省”字的情况

key = input("Input : ")
if "省" not in key:
    key += '省'
if key not in province_dict:
    print("暂未收录该省份的省会信息")
else:
    print("{}省的省会是{}".format(key, province_dict[key]))

word_count = {"hello":1,"world":0,"dalian":5,"liaoning":10,"python":6}
# 请输出hello出现的次数
print(word_count['hello'])

# 请对hello出现的次数增加1
word_count['hello'] += 1

# 请增加like出现的次数，设置初始值为1
word_count['like'] = 1
word_count['like'] += 1

# 请输出所有单词出现的次数，每行一个单词，单词和次数用冒号分隔
for i in word_count.items():
    print(i[0], ':', i[1])

