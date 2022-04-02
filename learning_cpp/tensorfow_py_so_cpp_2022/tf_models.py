import tensorflow as tf
import os

def save_model_ckpt(ckpt_file_path):
    x = tf.placeholder(tf.int32,name='x')
    y = tf.placeholder(tf.int32,name='y')
    b = tf.Variable(1,name='b')
    xy = tf.multiply(x,y)
    op = tf.add(xy,b,name='op_to_store')
    sess = tf.Session()
    sess.run(tf.global_variables_initializer())

    path = os.path.dirname(os.path.abspath(ckpt_file_path))
    if os.path.isdir(path) is False:
        os.makedirs(path)

    tf.train.Saver().save(sess,ckpt_file_path)

    feed_dict = {x:4,y:3}
    # print(sess.run(op,feed_dict))

save_model_ckpt('./model/model.ckpt')
