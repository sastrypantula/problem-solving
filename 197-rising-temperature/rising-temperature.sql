SELECT w2.id
FROM Weather w1
JOIN Weather w2
  ON DATE_ADD(w1.recordDate, INTERVAL 1 DAY) = w2.recordDate
 AND w1.temperature < w2.temperature;