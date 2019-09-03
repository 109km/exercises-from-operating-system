import sys
import re


def reform_file(file_name, callback):
    reformed_file_data = ""
    try:
        file_obj = open(file_name, "r")
        for line in file_obj.readlines():
            reformed_file_data = reformed_file_data + callback(line)
            
        file_obj.close()
        file_obj = open(file_name,'w')
        file_obj.write(reformed_file_data)
        file_obj.close()
        print("formed success!")
    except IOError:
        print("文件不存在 %s" % file_name)


def replace_string(matched):
    value = 'print(' + matched.group(2) + ')'
    print(value)
    return value

def replace_print_formats(content):
    pattern = r'(print[\s]{1})([\'\"]{1}.*)'
    fomated_file = re.sub(pattern, replace_string, content, 0)
    return fomated_file

file_name = sys.argv[1]

reform_file(file_name, replace_print_formats)
