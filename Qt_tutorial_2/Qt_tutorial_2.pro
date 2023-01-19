TEMPLATE = subdirs

SUBDIRS = calculator app

app.depends = calculator
