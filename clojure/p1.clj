(def ^:dynamic v 0) ; v is a global binding

(defn is-multiple-of-3-and-5 [num]
	(and
		(= 0 (mod num 3))
		(= 0 (mod num 5))
	)
)

( dotimes [x 1000]
	(cond
		(or
			(is-multiple-of-3-and-5 x)
			(= 0 (mod x 3))
			(= 0 (mod x 5))
		) (def v (+ x v))
		true nil
	)
)

(println v)
