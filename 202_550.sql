SELECT ROUND(
    sum( CASE
        WHEN a.event_date = DATE_ADD(b.first_login, INTERVAL 1 DAY)
        THEN 1 else 0
    END) / COUNT(DISTINCT a.player_id), 2) AS fraction
FROM Activity a
JOIN (
    SELECT player_id, MIN(event_date) AS first_login
    FROM Activity
    GROUP BY player_id
) b
ON a.player_id = b.player_id;