SELECT CAST(period.year as TEXT) || "-" ||CAST(period.month as TEXT) || "-" ||CAST(period.day as TEXT) as date
FROM period
ORDER BY period.month ASC;
