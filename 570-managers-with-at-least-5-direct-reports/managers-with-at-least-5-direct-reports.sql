# Write your MySQL query statement below
select name from Employee where id in (select managerId from Employee group by managerId having count(*)>=5) and id is not null;
