import smtplib
server = smtplib.SMTP('smtp.gmail.com',587)
server.ehlo_or_helo_if_needed()
server.starttls()
server.ehlo_or_helo_if_needed()
eid = ("varunbhatnagar115@gmail.com","varunb067@gmail.com")
server.login("cranesiotstudent@gmail.com","iotGatePass")
msg = "Hello varun this your first email recieved using raspberry pi"
server.sendmail("cranesiotstudent@gmail.com",eid,msg)
