(def result 0) 
(def cur 1)
(def prev 1)

(while (< cur 4000000)
  (def temp cur) 
  (def cur (+ cur prev))
  (def prev temp)
  (cond
    (= 0 (mod cur 2)) (def result (+ result cur))
    true nil
  )
)

(println result)

