SELECT CAST(period.year as TEXT) || "-" ||CAST(period.month as TEXT) || "-" ||CAST(period.day as TEXT) as logdate,
	   SUM(record.type * record.amount) as amount 
FROM record 
INNER JOIN period 
ON period.id = record.period_id
GROUP BY DATE(logdate,"0 year","0 month","0 day")
ORDER BY DATE(logdate,"0 year","0 month","0 day") DESC;