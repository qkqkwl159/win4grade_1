from flask import Flask
import pymysql

conn = pymysql.connect(host='0', user='root',password='147590',db='jun_test',charset='utf8')
cur = conn.cursor()

sql = 'select * from topics where id=1'
cur.execute(sql)
for row in cur:
    print(row[0], row[1])
    
conn.commit()
conn.close()
# app = Flask(__name__)

# user =  '''{
#     "id":1,
#     "user":"qkqkwl159",
#     "pwd":"12345",
#     "email":"qkqkwl159@naver.com"
#     }
#     '''
# @app.route('/')
# def home():
#     return 'This is home!'
# @app.route('/user')
# def Udata():
#     return user


# if __name__ == '__main__':
#     app.run('0.0.0.0', port=5000, debug=True)
