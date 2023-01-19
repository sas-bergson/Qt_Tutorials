TEMPLATE = subdirs

SUBDIRS = hello_msg_box app

app.depends = hello_msg_box
