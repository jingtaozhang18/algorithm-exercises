-- https://leetcode-cn.com/problems/game-play-analysis-v/
-- https://leetcode-cn.com/problems/game-play-analysis-v/solution/left-joinqiu-liu-cun-by-fsq247-hs41/
SELECT  d1                                               AS install_dt
       ,ROUND(COUNT(t1.player_id),2)                     AS installs
       ,ROUND(COUNT(t2.player_id)/COUNT(t1.player_id),2) AS Day1_retention
FROM
(
	SELECT  player_id
	       ,MIN(event_date) AS d1
	FROM Activity
	GROUP BY  player_id
) t1
LEFT JOIN
(
	SELECT  player_id
	       ,event_date AS d2
	FROM Activity
) t2
ON t1.player_id=t2.player_id AND DATE_SUB(d2, INTERVAL 1 DAY) = d1
GROUP BY  d1;