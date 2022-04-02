
import tensorflow as tf

def evaluate(pic):  
    sess = tf.Session()
    saver = tf.train.import_meta_graph('./model/model.ckpt.meta')
    saver.restore(sess, tf.train.latest_checkpoint('./model'))
    print(type(sess.run('b:0')))
    input_x = sess.graph.get_tensor_by_name('x:0')
    input_y = sess.graph.get_tensor_by_name('y:0')
    op = sess.graph.get_tensor_by_name('op_to_store:0')
    add_on_op = tf.multiply(op,2)
    ret = sess.run(add_on_op,{input_x:5,input_y:5})
    # print (ret)
    sess.close()
    return pic
evaluate(1)