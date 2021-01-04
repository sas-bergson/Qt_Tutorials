SELECT CAST(period.year as TEXT) || "-" ||CAST(period.month as TEXT) || "-" ||CAST(period.day as TEXT) as logdate,
	   (record.type * record.amount) as amount 
FROM record 
INNER JOIN period 
ON period.id = record.period_id
WHERE logdate LIKE "2020-12-26";