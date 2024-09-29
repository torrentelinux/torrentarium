-- 
-- Arbolito de Navidad para PostgreSQL.
-- Octulio Biletán * ver. 1.9.2024
-- Algoritmo recursivo.
-- Referencias: https://learnsql.es/blog/como-dibujar-un-arbol-de-navidad-en-sql/
-- Septiembre de 2024.
-- 

WITH RECURSIVE small_tree(tree_depth,pine) AS (
  SELECT 1 tree_depth,rpad(' ',10,' ') || '*' pine
  UNION ALL
  SELECT small_tree.tree_depth +1 tree_depth,
  rpad(' ',10-small_tree.tree_depth,' ') || rpad('*',small_tree.tree_depth+1,'.') || lpad('*',small_tree.tree_depth,'.') pine
  FROM small_tree
  where small_tree.tree_depth < 10
)
SELECT pine FROM small_tree;
