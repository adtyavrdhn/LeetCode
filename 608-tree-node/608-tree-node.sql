SELECT id,
CASE 
WHEN p_id IS NULL THEN "Root"
WHEN id IN (SELECt p_id from Tree) THEN "Inner"
ELSE "Leaf"
END AS Type
FROM Tree;
